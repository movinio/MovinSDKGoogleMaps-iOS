//
//  MapViewController.m
//  movin-example-app
//
//  Created by Tim Potze on 28/06/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import "MapViewController.h"

#import "AppDelegate.h"
#import "MapViewController.h"
#import <MovinSDKGoogleMaps/MovinSDKGoogleMaps.h>

@interface MapViewController () <MovinPositioningListener, MovinFloorChangedListener, GMSMapViewDelegate, MovinBeaconScannerListener>
@property(weak, nonatomic) IBOutlet MovinGMSMapView* map;
@end

@implementation MapViewController {
    // Holds the positioning engine instance which is used to determine the position of the user.
    MovinPositioningEngine* _positioningEngine;
    
    // Holds the beacon scanner
    MovinBeaconScanner* _beaconScanner;

    // Holds the marker which is placed at the position of the user.
    GMSMarker* _marker;
    
    // Holds the marker which is placed at the position of the nearest beacon.
    GMSMarker* _beaconMarker;
    
    // Holds the shape of the entity in which the current beacon is located.
    GMSPolygon* _currentEntityFigure;

    // Holds the button for following or unfollowing the user position.
    UIButton* _button;

    // Holds a count of positions provided by the positioning engine. This count is used to only perform an action for
    // every 5th provided position.
    int _positionSets;

    // Holds the current floor of the user.
    double _currentFloor;
}

#pragma mark - View Controller

- (void)viewDidLoad {
    [super viewDidLoad];

    _currentFloor = -99999;

    /*
     * Configure the map view by setting the map to the value stored in the AppDelegate instance, setting the delegate
     * to this view controller and setting the style of the map.
     */
    AppDelegate* delegate = (AppDelegate*)UIApplication.sharedApplication.delegate;
    self.map.map = delegate.map;
    self.map.delegate = self;

    /*
     * Disable the default GoogleMaps layer. To enable the default layer, remove the following line.
     */
    self.map.mapType = kGMSTypeNone;

    // Zoom in to make the map fit the bounds of the map.
    [self.map fitToMap];

    // Ask the user for permission to use their position.
    [[MovinLocationManager instance] requestWhenInUseAuthorization];

    /*
     * Create the positioning engine. If an error occurs while starting the positioning engine, display the error.
     * If no error has occurred, add this view controller as a positioning listener and initialize the engine.
     */
    NSError* err = nil;
    _positioningEngine = [delegate.map getPositioningEngine:&err];

    if (err != nil) {
        [self alertWithTitle:@"Failed to create positioning engine"
                  andMessage:err.localizedDescription
                 andCanClose:YES];
    }
    else {
        [_positioningEngine addPositioningListener:self];
        [_positioningEngine initialize];
    }
    
    /*
     * Create the MovinBeaconScanner
     */
    NSError* beaconScannerError = nil;
    _beaconScanner = [MovinSDK getBeaconScanner:&beaconScannerError];
    
    if(beaconScannerError != nil) {
        [self alertWithTitle:@"Failed to create the beacon scanner"
                  andMessage:beaconScannerError.localizedDescription
                 andCanClose:YES];
    } else {
        [_beaconScanner addMap:self.map.map];
    }

    /*
     * Create the Google Maps marker which will be constantly moved to the position of the user.
     */
    _marker = [GMSMarker markerWithPosition:CLLocationCoordinate2DMake(0, 0)];
    _marker.icon = [UIImage imageNamed:@"LocationMarker"];
    _marker.opacity = 0;
    _marker.groundAnchor = CGPointMake(0.5, 0.5);
    _marker.map = self.map;
    
    /*
     * Create the Google Maps marker which will constantly be moved to the position of the nearest beacon.
     */
    _beaconMarker = [GMSMarker markerWithPosition:CLLocationCoordinate2DMake(0, 0)];
    _beaconMarker.opacity = 0;
    _beaconMarker.map = self.map;

    /*
     * Create the button which toggles whether the position of the user will be followed. The size of the button is
     * based on the size of the frame of the floor switcher button. An arrow image will be set as the button image. The
     * tint of this image will be changed to indicate whether the "follow"-functionality is enabled or not.
     */
    CGRect buttonRect = CGRectMake(
            self.map.frame.size.width - self.map.floorSwitcher.frame.size.width * 2 - self.map.floorSwitcher.margin * 2,
            self.map.frame.size.height - self.map.floorSwitcher.frame.size.height - self.map.floorSwitcher.margin,
            self.map.floorSwitcher.frame.size.width,
            self.map.floorSwitcher.frame.size.height
    );

    _button = [[UIButton alloc] initWithFrame:buttonRect];

    _button.imageEdgeInsets = UIEdgeInsetsMake(10, 10, 10, 10);
    [_button setImage:[[UIImage imageNamed:@"LocationArrow"] imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate]
             forState:UIControlStateNormal];
    _button.imageView.tintColor = [UIColor blackColor];
    _button.autoresizingMask = UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleLeftMargin;
    _button.backgroundColor = self.map.floorSwitcher.unfocusedBackgroundColor;

    /*
     * Style the layer of the button like the floor switcher.
     */
    _button.layer.cornerRadius = self.map.floorSwitcher.cornerRadius;
    _button.layer.shadowOffset = CGSizeMake(0, 0);
    _button.layer.shadowRadius = 1.5;
    _button.layer.shadowOpacity = 0.5;
    _button.layer.masksToBounds = NO;
    _button.layer.zPosition = 999;

    // Add an action method to the button to handle touches inside the button.
    [_button addTarget:self action:@selector(toggleFollowPosition) forControlEvents:UIControlEventTouchUpInside];

    // Add the button as a subview to the map view.
    [self.map addSubview:_button];

    /*
     * The tile provider of the map is only available after the tile manifest has been loaded or the map style and
     * layer has been set.
     */
    [delegate.map getTileManifestWithCallback:^(MovinTileManifest* manifest, NSError* error) {
        if (manifest == nil) {
            [self alertWithTitle:@"Failed to load map" andMessage:error.localizedDescription andCanClose:false];
            return;
        }

        // Configure the tile provider to follow floor changes.
        [self.map.tileProvider addFloorChangedListener:self];

        // Toggle the "follow"-functionality to on.
        [self toggleFollowPosition];
    }];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];

    // When the view appears, start the position engine.
    if (_positioningEngine != nil && !_positioningEngine.isStarted) {
        [_positioningEngine start];
    }
    
    // Also start the beacon scanner
    if (_beaconScanner != nil) {
        [_beaconScanner startWithListener:self];
    }
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];

    // When the view disappears, stop the positioning engine.
    if (_positioningEngine != nil && _positioningEngine.isStarted) {
        [_positioningEngine stop];
    }
    
    // Also stop the beacon scanner
    if(_beaconScanner != nil) {
        [_beaconScanner stopWithListener:self];
    }
}

- (void)dealloc {
    /*
     * Remove this instance from the positioning engine's listeners when this view controller is being deallocated.
     */
    if (_positioningEngine != nil) {
        [_positioningEngine removePositioningListener:self];
    }
}

#pragma mark - Follow position button

- (void)toggleFollowPosition {
    /*
     * This method is invoked when the "follow position" button is tapped. Once tapped, toggle the followFloor value,
     * reset the _positionSets counter and change the tint of the image on the button according to the followFloor value.
     */
    if(self.map.tileProvider == nil) {
        return;
    }

    self.map.tileProvider.followFloor = !self.map.tileProvider.followFloor;
    _positionSets = 0;
    _button.imageView.tintColor = self.map.tileProvider.followFloor
            ? self.map.floorSwitcher.focusedBackgroundColor
            : [UIColor blackColor];
}

#pragma mark - Positioning engine

- (void)positioningEngineDidLoseConnection:(MovinPositioner*)engine {
    /*
     * This method is invoked when the positioning engine loses its connection to the server. This method may only be
     * invoked while the online positioning services are being used. Offline positioning shan't invoke this method.
     * Online positioning is only used while the data for offline positioning is still being downloaded.
     */
    NSLog(@"The connection disappeared.");
}

- (void)positioningEngineDidFindUnknownLocation:(MovinPositioner*)engine {
    /*
     * This method is invoked when the location of the user cannot be determined.
     */
    NSLog(@"You are located at an unknown location.");
}

- (void)positioningEngine:(MovinPositioner*)engine
        didUpdatePosition:(FloorPosition*)position {
    /*
     * This method is invoked when the position of the user has been updated. If position following has been enabled,
     * move the marker to the position of the user every fifth update.
     */
    _marker.position = position.position.CLLocation;
    _marker.opacity = self.map.tileProvider.floor == position.floor ? 1 : 0;

    if (self.map.tileProvider.followFloor) {
        _positionSets = ++_positionSets % 5;
        if (_positionSets == 0) {
            self.map.camera = [GMSCameraPosition cameraWithTarget:position.position.CLLocation
                                                             zoom:self.map.camera.zoom];
        }
    }
}

- (void)positioningEngine:(MovinPositioner*)engine
            didInitialize:(BOOL)success
                    error:(NSError*)error {
    /*
     * This method is invoked then the positioning engine has been initialized. The success value holds YES if the
     * initialisation has been completed successfully or NO if an error occurred. The error value holds an instance of
     * NSError representing the occurred error if the initialisation has failed.
     *
     * If the initialisation was successful, start the positioning engine. Otherwise, display the error message in an
     * alert dialog.
     */
    if (success) {
        [_positioningEngine start];
    } else {
        [self alertWithTitle:@"Could not start positioning"
                  andMessage:error.localizedDescription
                 andCanClose:YES];
    }
}

#pragma mark - Beacon scanner
-(void) beaconScanner:(MovinBeaconScanner *)scanner didChangeNearestBeacon:(MovinRangedBeacon *)beacon {
    /*
     * The nearest beacon was updated. The beacon property contains the new nearest beacon, or
     * if there are no more valid beacons nearby, it returns nil.
     * Update the room in which we are and the position marker of the beacon
     */
    // First remove the existing figures if they exist
    if(_currentEntityFigure != nil) {
        _currentEntityFigure.map = nil;
        _currentEntityFigure = nil;
    }
    _beaconMarker.opacity = 0;
    
    // Update the beacon marker
    if(beacon != nil) {
        _beaconMarker.position = beacon.beacon.position.position.CLLocation;
        _beaconMarker.opacity = 1;
    }
    
    // Find the entity in which we are
    [self.map.map getEntitiesInShape:beacon.beacon.position.position andFloor:beacon.beacon.position.floor andCallback:^(NSArray<MovinEntity *> * _Nullable entities, NSError * _Nullable error) {
        
        MovinEntity* entity = nil;
        
        // Find the entity which is of type Room or Hall
        for(MovinEntity* ent in entities) {
            if([ent.subType.baseType isEqualToString:@"Room"] ||
               [ent.subType.baseType isEqualToString:@"Hall"]) {
                entity = ent;
                break;
            }
        }
        if(entity == nil) {
            return;
        }
        
        // Create a GMSPolygon with the figure of this MovinEntity
        GMSMutablePath* path = [[GMSMutablePath alloc] init];
        for(GeoLatLng* coord in entity.geometry.pointsForIntersect) {
            [path addCoordinate:coord.CLLocation];
        }
        GMSPolygon* polygon = [GMSPolygon polygonWithPath:path];
        polygon.fillColor = [UIColor colorWithRed:0 green:0 blue:1 alpha:0.5];
        polygon.zIndex = 2;
        polygon.map = self.map;
        _currentEntityFigure = polygon;
    }];
    
}

-(BOOL) beaconScanner:(MovinBeaconScanner *)scanner isValidNearestBeacon:(MovinRangedBeacon *)beacon {
    /*
     * Only beacons with a known position are valid in the beacon scanner
     */
    return beacon.beacon.position != nil;
}

#pragma mark - Tile provider

- (void)tileProvider:(MovinTileProvider*)tileProvider
      didChangeFloor:(double)newFloor {
    /*
     * This method is invoked when the tile provider starts providing tiles for another floor. This can be caused by the
     * user tapping the floor change buttons or by the user moving their device to a different floor.
     *
     * If the value of followFloor has been changed to NO, the user must have manually changed the floor with the floor
     * switch buttons. Otherwise, the floor has changed by the user moving to a different floor.
     */
    if (!self.map.tileProvider.followFloor) {
        // Hide the marker and change the tint of the "follow floor"-button to black.
        _marker.opacity = 0;
        _button.imageView.tintColor = [UIColor blackColor];
    }
    else {
        // Hide or show the marker based on the current floor.
        _marker.opacity = newFloor == _currentFloor ? 1 : 0;
    }
}

#pragma mark - Map view

- (void)mapView:(GMSMapView*)mapView
       willMove:(BOOL)gesture {
    /*
     * This method is invoked by GoogleMaps when the map has moved. When the map has been moved by the user using a
     * gesture, disable the position following functionality and change the "follow position" button tint color
     * accordingly.
     */
    if (gesture && self.map.tileProvider.followFloor) {
        self.map.tileProvider.followFloor = NO;
        _positionSets = 0;
        _button.imageView.tintColor = [UIColor blackColor];
    }
}
@end
