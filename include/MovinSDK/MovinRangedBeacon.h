//
//  MovinRangedBeacon.h
//  libMovinSDK
//
//  Created by Movin Software on 07/03/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class MovinBeacon;
@class BeaconIdentifier;

@interface MovinRangedBeacon : NSObject

/// @abstract If known, the associated MovinBeacon to this beacon. Can be nil.
@property (readonly, nullable) MovinBeacon* beacon;
/// @abstract The estimated distance in meters of the device to this beacon.
@property (readonly) double distance;
/// @abstract The signal strength in dBm with which this beacon was measured.
@property (readonly) int rssi;
/// @abstract The CLProximity of this beacon, this is one of IMMEDIATE, NEAR, FAR or UNKNOWN.
@property (readonly) CLProximity proximity;
/// @abstract The beacon specific data, UUID, Major and Minor. Also accessible through the beacon property if that is not nil.
@property (readonly, nonnull) BeaconIdentifier* beaconIdentifier;

/**
 * @abstract Initializes a new MovinRangedBeacon.
 * @param beacon The corresponding MovinBeacon.
 * @param distance The distance in meters. This is the accuracy parameter of a CLBeacon.
 * @param rssi The RSSI at which the beacon was measured in dBm.
 * @param proximity The CLProximity of the beacon
 * @param beaconIdentifier The BeaconIdentifier, consisting of its UUID, Major and Minor.
 */
-(nonnull id) initWithMovinBeacon:(nullable MovinBeacon*) beacon andDistance:(double) distance andRssi:(int) rssi andProximity:(CLProximity) proximity andBeaconIdentifier:(nonnull BeaconIdentifier*) beaconIdentifier;

@end
