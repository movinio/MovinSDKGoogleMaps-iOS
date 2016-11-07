//
// Created by Tim Potze on 29/04/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MovinSDK/MovinSDK.h>
#import <GoogleMaps/GoogleMaps.h>

@class MovinMap;
@class MovinGMSTileLayer;
@class MovinFloorSwitcher;
@class MovinTileProvider;
@class MovinMapLayer;
@class MovinMapStyle;
@class MovinGMSMapView;
@protocol MovinGMSMapViewListener;
@class MovinGMSImageRendererManager;

/**
 * @class MovinGMSMapView
 * @brief Represents a map view which will automatically draw the Movin map, labels, markers and floor switcher. Each
 * feature can individually be disabled.
 */
@interface MovinGMSMapView : GMSMapView
/**
 * @brief Gets or sets the map layer which will be used to draw the map.
 */
@property(nullable) MovinMapLayer* movinMapLayer;
/**
 * @brief Gets or sets the map style which will be used to draw the map.
 */
@property(nullable) MovinMapStyle* movinMapStyle;
/**
 * @brief Gets or sets the map which will be used to draw.
 */
@property(nullable) MovinMap* movinMap;
/**
 * @brief Gets the tile provider which is used to provide tiles.
 */
@property(nullable, readonly) MovinTileProvider* tileProvider;
/**
 * @brief Gets the tile layer which provides the tiles to GoogleMaps.
 */
@property(nullable, readonly) MovinGMSTileLayer* tileLayer;
/**
 * @brief Gets the floor switcher button instance.
 */
@property(nonnull, readonly) MovinFloorSwitcher* floorSwitcher;
/**
 * @brief Gets the image renderer manager.
 */
@property(nonnull, readonly) MovinGMSImageRendererManager* imageRendererManager;

/**
 * @brief Gets or sets a value indicating whether the camera of this map view should automatically rotate based on
 * the heading of the compass of the current device.
 */
@property BOOL compassRotation;
/**
 * @brief Gets or sets the interval after each map view gesture in which the heading of the camera should not be
 * modified.
 */
@property NSTimeInterval compassRotationAfterGestureDelay;
/**
 * @brief Gets the MovinSmoothCompass instance used by this map view when compassRotation is set to YES.
 */
@property (readonly, nonnull) MovinSmoothCompass* compass;
/**
 * @brief Gets the timestamp the camera has been moved by a user gesture last.
 */
@property(readonly, nonnull) NSDate* lastCameraChangeByGesture;

/**
 * @brief Moves to camera to the currently set map and zoom in to make it fit the screen of the device.
 */
- (void)fitToMap;

/**
 * @brief Moves the camera to the currently set map and zooms to the specified zoom level.
 */
- (void)zoomOnMap:(float)zoom;
@end