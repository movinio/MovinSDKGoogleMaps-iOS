//
// Created by Tim Potze on 10/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MovinDataObject.h"

@class MovinBeacon;
@class MovinMap;

@interface MovinBeaconGroup : MovinDataObject
/**
 * @abstract Gets the beacons associated with this instance.
 */
@property(readonly, nullable) NSArray<MovinBeacon*>* beacons;
/**
 * @abstract Gets the map associated with this instance.
 */
@property (readonly, nullable, weak) MovinMap* map;

/**
 * @abstract Initializes a new MovinBeaconGroup object with the specified building and JSON data.
 * @param map The map the building is a member of.
 * @param json The JSON data.
 * @return A MovinBeaconGroup object with the specified building JSON data.
 */
- (nonnull id)initWithMap:(nonnull MovinMap*)map
                   andJson:(nonnull NSDictionary*)json;

@end