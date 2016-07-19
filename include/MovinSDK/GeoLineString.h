//
// Created by Tim Potze on 02/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GeoShape.h"

@class GeoLatLng;

@interface GeoLineString : GeoShape
/**
 * @abstract Contains the points of this line string.
 */
@property(readonly, nonnull) NSArray<GeoLatLng *> *points;

/**
 * @abstract Initializes a GeoLinearRing with the specified points.
 * @param points The points to initialize the ring with.
 * @return A GeoLinearRing object containing the specified points.
 */
- initWithPoints:(nonnull NSArray<GeoLatLng *> *)points;
@end