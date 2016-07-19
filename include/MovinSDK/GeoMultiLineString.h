//
// Created by Tim Potze on 03/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GeoShape.h"

@class GeoLineString;

@interface GeoMultiLineString : GeoShape
/**
 * @abstract Contains the line strings of this collection.
 */
@property(readonly, nonnull) NSArray<GeoLineString *>* lineStrings;

/**
 * @abstract Initializes a GeoMultiLineString with the specified line strings.
 * @param lineStrings The line strings to initialize the collection with.
 * @return A GeoMultiLineString object containing the specified collection of line strings.
 */
- initWithLineStrings:(nonnull NSArray<GeoLineString *>*)lineStrings;
@end