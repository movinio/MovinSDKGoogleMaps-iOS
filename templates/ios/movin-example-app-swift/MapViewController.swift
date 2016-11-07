//
//  MapViewController.swift
//  movin-example-app-swift
//
//  Created by Tim Potze on 18/07/16.
//  Copyright © 2016 Movin. All rights reserved.
//

import UIKit
import GoogleMaps

class MapViewController: BaseViewController, GMSMapViewDelegate, MovinFloorChangedListener, MovinPositioningListener {
    @IBOutlet weak var map: MovinGMSMapView!

    // Holds the positioning engine instance which is used to determine the position of the user.
    private var positioningEngine: MovinPositioningEngine?

    // Holds the marker which is placed at the position of the user.
    private var marker: GMSMarker!

    // Holds the button for following or unfollowing the user position.
    private var button: UIButton!

    // Holds a count of positions provided by the positioning engine. This count is used to only perform an action for
    // every 5th provided position.
    private var positionSets = 0

    // Holds the current floor of the user.
    private var currentFloor = -99999.0

    override func viewDidLoad() {
        super.viewDidLoad()

        /*
         * Configure the map view by setting the map to the value stored in the AppDelegate instance, setting the delegate
         * to this view controller and setting the style of the map.
         */
        let delegate = UIApplication.shared.delegate as! AppDelegate
        map.movinMap = delegate.map
        map.delegate = self

        /*
         * Disable the default GoogleMaps layer. To enable the default layer, remove the following line.
         */
        map.mapType = GoogleMaps.kGMSTypeNone

        // Zoom in to make the map fit the bounds of the map.
        map.fitToMap()

        /*
         * Ask the user for permission to use their position.
         */
        MovinLocationManager.instance().requestWhenInUseAuthorization()

        /*
         * Create the positioning engine. If an error occurs while starting the positioning engine, display the error.
         * If no error has occurred, add this view controller as a positioning listener and initialize the engine.
         */
        do {
            positioningEngine = try delegate.map!.getPositioningEngine()

            positioningEngine!.add(self)
            positioningEngine!.initialize()
        } catch let error as NSError {
            self.alert(title: "Failed to create positioning engine", message: error.localizedDescription, canClose: true)
            return
        }

        /*
         * Create the Google Maps marker which will be constantly moved to the position of the user.
         */
        marker = GMSMarker(position:CLLocationCoordinate2DMake(0, 0))
        marker.icon = UIImage(named:"LocationMarker")
        marker.opacity = 0
        marker.groundAnchor = CGPoint(x: 0.5, y: 0.5)
        marker.map = map;
        
        let mapWidth:Float = Float(map.frame.size.width)
        let mapHeight:Float = Float(map.frame.size.height)
        let buttonWidth:Float = Float(map.floorSwitcher.frame.size.width)
        let buttonHeight:Float = Float(map.floorSwitcher.frame.size.height)
        let margin:Float = map.floorSwitcher.margin;
        let buttonRect = CGRect(x: Int(mapWidth - buttonWidth * 2 - margin * 2),
                                y:Int(mapHeight - buttonHeight - margin),
                                width: Int(buttonWidth),
                                height: Int(buttonHeight))

        button = UIButton(frame: buttonRect)
        button.imageEdgeInsets = UIEdgeInsets(top:10, left:10, bottom:10, right:10)
        button.setImage(UIImage(named:"LocationArrow")!.withRenderingMode(.alwaysTemplate), for: UIControlState.normal)
        button.imageView!.tintColor = UIColor.black
        button.autoresizingMask = [.flexibleTopMargin, .flexibleLeftMargin]
        button.backgroundColor = map.floorSwitcher.unfocusedBackgroundColor

        /*
         * Style the layer of the button like the floor switcher.
         */
        button.layer.cornerRadius = CGFloat(map.floorSwitcher.cornerRadius)
        button.layer.shadowOffset = CGSize()
        button.layer.shadowRadius = 1.5
        button.layer.shadowOpacity = 0.5
        button.layer.masksToBounds = false
        button.layer.zPosition = 999

        button.addTarget(self, action:#selector(toggleFollowPosition), for: .touchUpInside)

        // Add the button as a subview to the map view.
        map.addSubview(button)

        /*
         * The tile provider of the map is only available after the tile manifest has been loaded or the map style and
         * layer has been set.
         */
        delegate.map!.getTileManifest {
            (manifest: MovinTileManifest?, error: Error?) -> () in
            if manifest == nil {
                self.alert(title: "Failed to load map", message:error!.localizedDescription, canClose:false)
                return
            }

            // Use the default layers and styles
            self.map.movinMapStyle = manifest!.defaultStyle;
            self.map.movinMapLayer = manifest!.defaultLayer;

            // Configure the tile provider to follow floor changes.
            self.map.tileProvider!.add(self)

            // Toggle the "follow"-functionality to on.
            self.toggleFollowPosition()
        }
    }

    override func viewDidAppear(_ animated:Bool) {
        super.viewDidAppear(animated)

        // When the view appears, start the position engine.
        if positioningEngine != nil && positioningEngine!.isStarted() {
            positioningEngine!.start()
        }
    }

    override func viewDidDisappear(_ animated:Bool) {
        super.viewDidDisappear(animated)

        // When the view disappears, stop the positioning engine.
        if positioningEngine != nil && positioningEngine!.isStarted() {
            positioningEngine!.stop()
        }
    }

    deinit {
        /*
         * Remove this instance from the positioning engine's listeners when this view controller is being deallocated.
         */
        if positioningEngine != nil {
            self.positioningEngine!.remove(self);
        }
    }

    func toggleFollowPosition() {
        /*
         * This method is invoked when the "follow position" button is tapped. Once tapped, toggle the followFloor value,
         * reset the _positionSets counter and change the tint of the image on the button according to the followFloor value.
         */
        if map.tileProvider == nil {
            return
        }

        map.tileProvider!.followFloor = !map.tileProvider!.followFloor
        positionSets = 0
        
        button.imageView!.tintColor = map.tileProvider!.followFloor
                ? map.floorSwitcher.focusedBackgroundColor
                : UIColor.black
    }
    
    func positioningEngineDidLoseConnection(_ engine: MovinPositioner) {
        /*
         * This method is invoked when the positioning engine loses its connection to the server. This method may only be
         * invoked while the online positioning services are being used. Offline positioning shan't invoke this method.
         * Online positioning is only used while the data for offline positioning is still being downloaded.
         */
        print("The connection disappeared")
    }

    func positioningEngineDidFindUnknownLocation(_ engine: MovinPositioner) {
        /*
         * This method is invoked when the location of the user cannot be determined.
         */
        print("You are located at an unknown location.")
    }

    func positioningEngine(_ engine: MovinPositioner, didUpdate position: FloorPosition) {
        /*
         * This method is invoked when the position of the user has been updated. If position following has been enabled,
         * move the marker to the position of the user every fifth update.
         */
        marker.position = position.position.clLocation;
        marker.opacity = map.tileProvider!.floor == position.floor ? 1 : 0;

        if (map.tileProvider!.followFloor) {
            positionSets += 1
            positionSets = positionSets % 5;
            if (positionSets == 0) {
                map.camera = GMSCameraPosition.camera(withTarget: position.position.clLocation, zoom:map.camera.zoom)
            }
        }
    }

    func positioningEngine(_ engine: MovinPositioner, didInitialize success:Bool, error: Error?) {
        /*
         * This method is invoked then the positioning engine has been initialized. The success value holds true if the
         * initialisation has been completed successfully or false if an error occurred. The error value holds an instance of
         * NSError representing the occurred error if the initialisation has failed.
         *
         * If the initialisation was successful, start the positioning engine. Otherwise, display the error message in an
         * alert dialog.
         */
        if success {
            positioningEngine!.start()
        } else {
            self.alert(title: "Could not start positioning", message:error!.localizedDescription, canClose:true)
        }
    }
    
    func tileProvider(_ tileProvider: MovinTileProvider, didChangeFloor newFloor: Double) {
        /*
         * This method is invoked when the tile provider starts providing tiles for another floor. This can be caused by the
         * user tapping the floor change buttons or by the user moving their device to a different floor.
         *
         * If the value of followFloor has been changed to false, the user must have manually changed the floor with the floor
         * switch buttons. Otherwise, the floor has changed by the user moving to a different floor.
         */
        if map.tileProvider!.followFloor {
            // Hide the marker and change the tint of the "follow floor"-button to black.
            marker.opacity = 0;
            button.imageView!.tintColor = UIColor.black
        }
        else {
            // Hide or show the marker based on the current floor.
            marker.opacity = newFloor == currentFloor ? 1 : 0
        }
    }
    
    func mapView(_ mapView: GMSMapView, willMove gesture:Bool) {
        /*
         * This method is invoked by GoogleMaps when the map has moved. When the map has been moved by the user using a
         * gesture, disable the position following functionality and change the "follow position" button tint color
         * accordingly.
         */
        if (gesture && map.tileProvider!.followFloor) {
            map.tileProvider!.followFloor = false
            positionSets = 0
            button.imageView!.tintColor = UIColor.black
        }
    }
}
