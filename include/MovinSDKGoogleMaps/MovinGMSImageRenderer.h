//
//  MovinGMSImageRenderer.h
//  TestDrawingLabels
//
//  Created by Tim Potze on 15/08/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GoogleMaps/GoogleMaps.h>
#import <MovinSDK/MovinSDK.h>

@class MovinGMSMapView;

/**
 * Represents an object which can be drawn on a MovinGMSMapView.
 */
@interface MovinGMSImageRenderer : NSObject

/**
 * Gets or sets the map this image renderer should draw on.
 */
@property MovinGMSMapView* map;
/**
 * Gets or sets the position where the image should be drawn to.
 */
@property GeoLatLng* position;
/**
 * Gets or sets the floor the image should be drawn on.
 */
@property double floor;
/**
 * Gets the image which will be drawn.
 */
@property(readonly) UIImage* image;
/**
 * Gets or sets the bearing of the image.
 */
@property float bearing;
/**
 * Gets or sets the bounds in which the image should be drawn.
 */
@property GeoShape* bounds;
/**
 * Gets or sets the scaling style of the image.
 */
@property MovinTileStyleScaling scaling;
/**
 * Gets or sets the rotation style of the image.
 */
@property MovinTileStyleRotation rotation;
/**
 * Gets or sets the size of a pixel in meters on zoom level 0.
 */
@property float metersPerPixel;
/**
 * Gets or sets the zoom level at which the sizing is based when the sizingStyle is set to
 * MovinGMSSizingStyleFixed.
 */
@property float fixedZoomLevel;
/**
 * Gets or sets the minimum zoom level from which the image is visible.
 */
@property float minZoomLevel;
/**
 * Gets or sets the maximum zoom level to which the image is visible.
 */
@property float maxZoomLevel;

/**
 * Gets or sets the opacity of the image.
 */
@property float opacity;

/**
 * Gets or sets the anchor point of the image.
 */
@property CGPoint anchor;

/**
 * Gets a value indicating whether this element is visible.
 */
@property(readonly) BOOL visible;

/**
 * Gets the size of the image.
 */
@property(readonly) CGSize imageSize;

/**
 * Gets the size the image should have on a GMSGroundOverlay.
 */
@property(readonly) CGSize overlaySize;

/**
 * Gets the bearing the image should have on a GMSGroundOverlay.
 */
@property(readonly) double overlayBearing;

/**
 * Invalidates the image of this instance and requests the image to be re-rendered. This method should only
 * every be called by subclasses of MovinGMSImageRenderer.
 */
- (void)invalidate;

/**
 * This method is called by the invalidation process when a new image should be rendered. This method should
 * be overridden by subclasses of MovinGMSImageRenderer and should not be called by any class other than
 * MovinGMSImageRenderer.
 */
- (void)renderImage:(void (^)(UIImage*))responder;

@end
