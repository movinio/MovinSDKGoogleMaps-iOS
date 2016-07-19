//
//  GeoLatLng.h
//  MovinCore
//
//  Created by Movin Software on 26/03/15.
//  Copyright (c) 2015 Movin Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "GeoShape.h"

@interface GeoLatLng : GeoShape
/**
 * @abstract Gets the latitude of this geo coordinate.
 */
@property (readonly) double lat;
/**
 * @abstract Gets the longitude of this geo coordinate.
 */
@property (readonly) double lng;
/**
 * @abstract Gets a CLLocationCoordinate2D instance representing the same geographical coordinate.
 */
@property (readonly) CLLocationCoordinate2D CLLocation;

/**
 * @abstract Initializes a new GeoLatLng coordinate with a latitude and longitude values.
 * @param lat The latitude.
 * @param lng The longitude.
 * @return A GeoLatLng object with the specified latitude and longitude values.
 */
-(id) initWithLat:(double) lat andLng:(double) lng;

@end

