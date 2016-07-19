//
// Created by Tim Potze on 02/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GeoShape.h"

@class GeoLinearRing;

@interface GeoPolygon : GeoShape
/**
 * @abstract Contains the rings of this polygon.
 */
@property(readonly, nonnull) NSArray<GeoLinearRing *> *rings;

/**
 * @abstract Initializes a GeoPolygon with the specified rings.
 * @param points The rings to initialize the ring with.
 * @return A GeoPolygon object containing the specified rings.
 */
- (nonnull id)initWithRings:(nonnull NSArray<GeoLinearRing *>*)rings;
@end