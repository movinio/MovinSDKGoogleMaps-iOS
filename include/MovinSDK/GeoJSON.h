//
// Created by Tim Potze on 02/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GeoLatLng;
@class GeoShape;

@interface GeoJSON : NSObject
/**
 * @abstract Parses the specified data into an instance of GeoLatLng.
 * @param jsonData The JSON data to parse.
 * @returns An GeoLatLng object with the values specified in the json data.
 */
+ (nullable GeoLatLng *)parsePoint:(nullable NSArray *)jsonData;

/**
 * @abstract Serializes an instance of GeoLatLng into an array representing the point.
 * @param point The point to serialize.
 * @returns An array containing the point information.
 */
+ (nullable NSArray *)serializePoint:(nullable GeoLatLng *)point;

/**
 * @abstract Parses the specified data into a shape.
 * @param jsonData The JSON data to parse.
 * @return An object of a subclass of GeoShape which represents the shape.
 */
+ (nullable GeoShape*)parseGeometry:(nullable NSDictionary *)jsonData;
@end