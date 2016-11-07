//
// Created by Tim Potze on 25/04/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMaps/GoogleMaps.h>

@class MovinTileProvider;
@class MovinGMSMapView;

/**
 * @class MovinGMSTileLayer
 * @brief Represents a tile layer which will render tiles provided by the MovinSDK.
 */
@interface MovinGMSTileLayer : GMSTileLayer
/**
 * @brief Initializes a new MovinGMSTileLayer object with the specified map view.
 * @param mapView The map view to render on.
 * @return A MovinGMSTileLayer object with the specified map view.
 */
- (nonnull id) initWithMapView:(nonnull MovinGMSMapView*)mapView;

/**
 * @brief Gets the tile provider this layer used the tiles of.
 */
@property (nullable, setter=setMovinTileProvider:)MovinTileProvider* tileProvider;

@end