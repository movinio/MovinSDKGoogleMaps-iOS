//
//  MovinPositioningEngine.h
//  MovinPositioningSDK
//
//  Created by Movin Software on 16/03/15.
//  Copyright (c) 2015 Movin Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>
#import "MovinPositioner.h"

@class FloorPosition;
@class MovinMap;
@class MovinBeaconScanner;

@interface MovinPositioningEngine : MovinPositioner
// Initialize
/**
 * @abstract Initializes a new MovinPositioningEngine with a map.
 * @param map The map in which this positioning engine should work.
 * @param scanner The MovinBeaconScanner that this positioning engine will use to scan for beacons.
 * @return A MovinPositioningEngine object with the specified map.
 */
-(nonnull id)initWithMap: (nonnull MovinMap*)map andBeaconScanner:(nonnull MovinBeaconScanner*) scanner;

/**
 * @abstract Initializes the MovinPositioningEngine, which will download the required positioning database if and will fallback to online positioning if offline positioning is not available.
 * Initialization will start automatically if the positioning engine is started without calling initialize.
 */
-(void)initialize;

// Heading
/**
 * @abstract Gets the heading the device is oriented at in radians based on True North
 * @return The angle between True North and the device orientation in radians
 */
-(double) getHeading;

// State
/**
 * @abstract Returns whether or not the MovinPositioningEngine has yet been initialized
 */
-(BOOL) isInitialized;
@end
