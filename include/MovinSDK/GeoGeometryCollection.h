//
// Created by Tim Potze on 03/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GeoShape.h"

@interface GeoGeometryCollection : GeoShape
/**
 * @abstract Contains the geometries of this geometry collection.
 */
@property(readonly, nonnull) NSArray<GeoShape*> *geometries;

/**
 * @abstract Initializes a GeoGeometryCollection with the specified geometries.
 * @param geometries The geometries to initialize the collection with.
 * @return A GeoGeometryCollection object containing the specified collection of geometries.
 */
- initWithGeometries:(nonnull NSArray<GeoShape*>*)geometries;
@end