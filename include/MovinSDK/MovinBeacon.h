//
// Created by Tim Potze on 10/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BeaconIdentifier.h"
#import "MovinDataObject.h"

@class MovinBeaconGroup;
@class GeoLatLng;
@class FloorPosition;

@interface MovinBeacon : MovinDataObject
/**
 * @abstract Gets the reference id of this instance.
 */
@property(readonly, nonnull) NSString* referenceId;
/**
 * @abstract Gets the group this instance is a member of.
 */
@property(readonly, weak, nullable) MovinBeaconGroup* group;
/**
 * @abstract Gets the position of this instance.
 */
@property(readonly, nullable) FloorPosition* position;
/**
 * @abstract Gets the beacon code of this instance.
 */
@property(readonly, nonnull) NSString* beaconCode;
/**
 * @abstract Gets the UUID, Major and Minor of this instance.
 */
@property(readonly, nullable) BeaconIdentifier* identifier;
/**
 * @abstract Gets the status of this instance.
 */
@property(readonly, nonnull) NSString* status;
/**
 * @abstract Gets the type of this instance.
 */
@property(readonly, nonnull) NSString* type;
/**
 * @abstract Gets whether or not the beacon's UUID, Major and Minor are shuffled.
 */
@property(readonly) BOOL shuffled;
/**
 * @abstract Gets the beacon identifiers that this beacon has broadcasted, is broadcasting and/or will broadcast in the future.
 */
@property(readonly, nullable) NSArray<BeaconIdentifier*>* shuffledIds;
/**
 * @abstract The ProximityUUID with which this beacon will broadcast if secure suffling is turned on.
 */
@property(readonly, nullable) NSUUID* secureUuid;

/**
 * @abstract Initializes a new MovinDataObject object with the specified JSON data and beacon group.
 * @param group The beacon group.
 * @param json The JSON data.
 * @return A MovinDataObject object with the specified JSON data and beacon group.
 */
- (nonnull id)initWithGroup:(nonnull MovinBeaconGroup*)group andJson:(nonnull NSDictionary*)json;
@end
