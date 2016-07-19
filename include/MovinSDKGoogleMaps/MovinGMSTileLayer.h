//
// Created by Tim Potze on 25/04/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMaps/GoogleMaps.h>

@class MovinTileProvider;

@interface MovinGMSTileLayer : GMSTileLayer

/**
 * @abstract Gets the tile provider this layer used the tiles of.
 */
@property (nullable, setter=setMovinTileProvider:)MovinTileProvider* tileProvider;

/**
 * @abstract Initializes a new MovinGMSTileLayer object with the specified tile provider.
 * @param The tile provider to use the tiles of.
 * @return A MovinGMSTileLayer object with the specified tile provider.
 */
- (nullable id)initWithTileProvider:(nonnull MovinTileProvider*)tileProvider;

/**
 * @abstract Creates a MovinGMSTileLayer with the specified tile provider and adds it to the specified map view.
 * @param mapView The map view to add the tile layer to.
 * @param tileProvider The tile provider to use the tiles of.
 * @return A MovinGMSTileLayer object with the specified tile provider which has been added to the specified map view.
 */
+ (nonnull MovinGMSTileLayer*)createLayerForMap:(nonnull GMSMapView*)mapView
                        andTileProvider:(nullable MovinTileProvider*)tileProvider;
@end