//
// MovinGMSMapViewListener.h
// MovinSDKGoogleMaps
//
// Copyright © 2017 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MovinGMSMapView;
@class MovinMap;
@class MovinMapStyle;
@class MovinMapLayer;
@class MovinTileProvider;
@class MovinGMSImageRenderer;

/**
 * Contains methods for listening to events occurring in a MovinGMSMapView instance.
 */
@protocol MovinGMSMapViewListener<NSObject>

@optional
/**
 * A map has been assigned to the map view.
 *
 * @param mapView The map view.
 * @param map The assigned map.
 */
- (void)mapView:(MovinGMSMapView*)mapView
      didSetMap:(MovinMap*)map;

/**
 * A map style has been assigned to the map view.
 *
 * @param mapView The map view.
 * @param mapStyle The assigned map style.
 */
- (void)mapView:(MovinGMSMapView*)mapView
 didSetMapStyle:(MovinMapStyle*)mapStyle;

/**
 * A map layer has been assigned to the map view.
 *
 * @param mapView The map view.
 * @param mapLayer The assigned map layer.
 */
- (void)mapView:(MovinGMSMapView*)mapView
 didSetMapLayer:(MovinMapLayer*)mapLayer;

/**
 * A tile provider has been assigned to the map view.
 *
 * @param mapView The map view.
 * @param tileProvider The assigned tile provider.
 */
- (void)   mapView:(MovinGMSMapView*)mapView
didSetTileProvider:(MovinTileProvider*)tileProvider;

/**
 * An image renderer has been tapped within the map view.
 *
 * @param mapView The map view.
 * @param imageRenderer The tapped image renderer.
 */
- (void)    mapView:(MovinGMSMapView*)mapView
didTapImageRenderer:(MovinGMSImageRenderer*)imageRenderer;

@end