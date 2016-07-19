//
//  MovinPosition.h
//  MovinCore
//
//  Created by Movin Software on 17/03/15.
//  Copyright (c) 2015 Movin Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GeoLatLng;

@interface FloorPosition : NSObject <NSCopying>
/**
 * @abstract The geographical position
 */
@property (readonly,nonnull) GeoLatLng* position;
/**
 * @abstract The floor the position is on
 */
@property double floor;

/**
 * @abstract Initializes a new FloorPosition for the given position and floor
 * @param position The position of this FloorPosition
 * @param floor The floor of this FloorPosition
 * @return A new instance of FloorPosition
 */
-(nonnull id) initWithGeoLatLng:(nonnull GeoLatLng *) position
               andFloor: (double) floor;

/**
 * @abstract Returns a JSON representation of this FloorPosition
 */
-(nonnull NSDictionary*) toJSON;

/**
 * @abstract Creates a FloorPosition instance from the given JSON data
 */
+(nullable id) fromJson:(nullable NSDictionary*) jsonData;
@end
