//
// Created by Tim Potze on 12/04/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>

@class MovinMap;
@protocol MovinFloorChangedListener;
@class MovinTileManifest;
@class MovinMapLayer;
@class MovinMapStyle;

@interface MovinTileProvider : NSObject
@property(nonnull, readonly) MovinMapStyle* style;
@property(nonnull, readonly) MovinMapLayer* layer;
@property double floor;
@property BOOL followFloor;

/**
 * @abstract Initializes a new MovinTileProvider object with the specified layer and style.
 * @param layer The map layer to provide tiles for.
 * @param style The map style to provide tiles for.
 * @return A MovinTileProvider object with the specified layer and style.
 */
- (nonnull id)initWithLayer:(nonnull MovinMapLayer*)layer
                   andStyle:(nonnull MovinMapStyle*)style;

/**
 * @abstract Adds the specified floor changed listener to this instance. Once the active floor has changed, the
 * listener will be notified.
 * @param listener An instance which implements the MovinFloorChangedListener protocol.
 */
- (void)addFloorChangedListener:(nonnull id <MovinFloorChangedListener>)listener;

/**
 * @abstract Removes the specified floor changed listener from this instance.
 * @param listener An instance which implements the MovinFloorChangedListener protocol.
 */
- (void)removeFloorChangedListener:(nonnull id <MovinFloorChangedListener>)listener;

/**
 * @abstract Gets the tile at the specified x, y and zoom. Once the tile has been loaded, the specified callback will
 * be invokes with the tile image or an error if the image failed to load. The tile image will be nil when no image is
 * available for the specified location or an error occurred.
 * @param x The X-coordinate of the tile.
 * @param y The Y-coordinate of the tile.
 * @param z The zoom level of the tile.
 * @param callback The callback to invoke once the tile has been loaded.
 */
- (void)getTileWithX:(int)x
                andY:(int)y
                andZ:(int)z
         andCallback:(nonnull void (^)(UIImage* _Nullable, NSError* _Nullable))callback;
@end