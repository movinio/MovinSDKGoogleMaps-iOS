//
// Created by Tim Potze on 03/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GeoShape.h"

@class GeoPolygon;


@interface GeoMultiPolygon : GeoShape
/**
 * @abstract Contains the polygons of this collection.
 */
@property(readonly, nonnull) NSArray<GeoPolygon *>* polygons;

/**
 * @abstract Initializes a GeoMultiPolygon with the specified polygons.
 * @param polygons The polygons to initialize the collection with.
 * @return A GeoMultiPolygon object containing the specified collection of polygons.
 */
- initWithPolygons:(nonnull NSArray<GeoPolygon *>*)polygons;
@end