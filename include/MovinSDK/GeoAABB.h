//
// Created by Tim Potze on 04/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GeoShape.h"

@interface GeoAABB : GeoShape
/**
 * @abstract Gets the origin of this axis aligned bounding box.
 */
@property(readonly, nonnull) GeoLatLng* origin;
/**
 * @abstract Gets the width of this axis aligned bounding box.
 */
@property(readonly) double width;
/**
 * @abstract Gets the height of this axis aligned bounding box.
 */
@property(readonly) double height;
/**
 * @abstract Gets the leftmost longitude coordinate.
 */
@property(readonly) double leftLng;
/**
 * @abstract Gets the rightmost longitude coordinate.
 */
@property(readonly) double rightLng;
/**
 * @abstract Gets the topmost latitude coordinate.
 */
@property(readonly) double topLat;
/**
 * @abstract Gets the bottommost latitude coordinate.
 */
@property(readonly) double bottomLat;
/**
 * @abstract Gets the size of this box.
 */
@property(readonly) double size;
/**
 * @abstract Initializes a new GeoAABB object with the specified origin and size.
 * @param origin The origin.
 * @param width The width.
 * @param height The height.
 * @returns An GeoAABB object with the specified origin and size.
 */
- (nonnull id)initWithOrigin:(nonnull GeoLatLng*)origin andWidth:(double)width andHeight:(double)height;

/**
 * Gets a value indicating whether the specified box intersects with this instance.
 */
- (BOOL)intersectsWithAABB:(nonnull GeoAABB*) box;
@end