//
// Created by Tim Potze on 05/07/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MovinTileManifest;
@class MovinTileProvider;
@class MovinMapLayer;


@interface MovinMapStyle : NSObject
/**
 * @abstract Gets the tile manifest this layer is a member of.
 */
@property(nullable, readonly, weak) MovinTileManifest* tileManifest;
/**
 * @abstract Gets the name of this layer.
 */
@property(nonnull, readonly) NSString* name;

/**
 * @abstract Initializes a new MovinMapStyle object with the specified tile manifest and name.
 * @param tileManifest The tile manifest the layer is a member of.
 * @param name The name of the layer.
 * @return A MovinMapStyle object with the specified tile manifest and name.
 */
- (nonnull id)initWithTileManifest:(nonnull MovinTileManifest*)tileManifest
                           andName:(nonnull NSString*)name;

/**
 * @abstract Create a MovinTileProvider for the specified layer with this style.
 */
- (nullable MovinTileProvider*)createTileProviderWithLayer:(nonnull MovinMapLayer*)layer
                                                  andError:(NSError* _Nullable * _Nullable)error;

/**
 * @abstract Create a MovinTileProvider for the layer with the specified name with this style.
 */
- (nullable MovinTileProvider*)createTileProviderWithLayerName:(nonnull NSString*)layerName
                                                      andError:(NSError* _Nullable * _Nullable)error;
@end