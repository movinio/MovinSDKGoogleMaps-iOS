//
// Created by Tim Potze on 29/04/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MovinTileProvider;
@class MovinGMSTileLayer;
@class GMSMapView;
@class GMSMarker;


@interface MovinGMSPOIManager : NSObject

/**
 * @abstract Gets the tile provider this layer used the points of interest of.
 */
@property(nullable) MovinTileProvider* tileProvider;

/**
 * @abstract Gets the map view this points of interest manager will manage the points of interest of.
 */
@property(nonnull) GMSMapView* mapView;

/**
 * @abstract Gets the active markers on the current floor.
 */
@property(nullable,readonly) NSArray<GMSMarker*>* markers;

/**
 * @abstract Initializes a new MovinGMSPOIManager object with the specified tile provider and map view.
 * @param tileProvider The tile provider to use the points of interest of.
 * @param mapView The map view to add the markers to.
 * @return A MovinGMSPOIManager object with the specified tile provider.
 */
- (nullable id)initWithTileProvider:(nullable MovinTileProvider*)tileProvider
                andMapView:(nonnull GMSMapView*)mapView;
@end