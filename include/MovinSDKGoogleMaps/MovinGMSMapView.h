//
// Created by Tim Potze on 29/04/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMaps/GoogleMaps.h>

@class MovinMap;
@class MovinGMSTileLayer;
@class MovinFloorSwitcher;
@class MovinMapLayer;
@class MovinMapStyle;
@class MovinGMSPOIManager;


@interface MovinGMSMapView : GMSMapView
@property(nullable) MovinMapLayer* mapLayer;
@property(nullable) MovinMapStyle* mapStyle;
@property(nullable) MovinMap* map;

@property(nullable, readonly) MovinTileProvider* tileProvider;
@property(nullable, readonly) MovinGMSPOIManager* poiManager;
@property(nullable, readonly) MovinGMSTileLayer* tileLayer;
@property(nonnull, readonly) MovinFloorSwitcher* floorSwitcher;

- (void)fitToMap;

- (void)zoomOnMap:(float)zoom;
@end