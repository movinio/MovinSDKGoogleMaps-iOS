//
//  MovinPositioner.h
//  MovinSDK
//
//  Created by Movin Software on 20/11/15.
//  Copyright © 2015 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MovinPositioningListener;
@class FloorPosition;

@interface MovinPositioner : NSObject
-(void) onStart;
-(void) onStop;

/**
 * @abstract Starts the MovinPositioner
 */
-(void) start;
/**
 * @abstract Stops the MovinPositioner
 */
-(void) stop;

/**
 * @abstract Returns whether or not the MovinPositioner is started
 * @return If the positioner is started or not
 */
-(BOOL) isStarted;

/**
 * @abstract Adds a positioning listener
 * @param listener Any class instance that has implemented the MovinPositioningListener protocol
 */
-(void) addPositioningListener:(nonnull id<MovinPositioningListener>) listener;
/**
 * @abstract Removes an earlier added positioning listener
 * @param listener The earlier added listener to remove
 */
-(void) removePositioningListener:(nonnull id<MovinPositioningListener>) listener;


-(void) callInitialized:(BOOL) success error:(nullable NSError*) error;
-(void) callUpdatePosition:(nonnull FloorPosition*) position;
-(void) callUnknownLocation;
-(void) callLostConnection;
-(nonnull NSArray *) getPositioningListeners;
@end

// Callback delegate
@protocol MovinPositioningListener <NSObject>
@optional

/**
 * @abstract Optional method, called once the MovinPositioner finished initializing.
 * @param success Whether or not the MovinPositioner was successfully initialized
 * @param error If the MovinPositioner failed to initialize, the error contains what went wrong
 */
-(void)positioningEngine:(nonnull MovinPositioner*)engine
           didInitialize:(BOOL)success
                   error: (nullable NSError*) error;
/**
 * @abstract Optional method, called when a new position is calculated
 * @param position The position that is calculated
 */
-(void)positioningEngine:(nonnull MovinPositioner*)engine
       didUpdatePosition:(nonnull FloorPosition*) position;
/**
 * @abstract Optional method, called when the MovinPositioner lost connection to the internet. This is only relevant
 * for online-positioning. Offline-positioning will never call this. The SDK will default to OfflinePositioning, but if
 * that is unavailable it will use OnlinePositioning.
 */
-(void)positioningEngineDidLoseConnection:(nonnull MovinPositioner*)engine;
/**
 * @abstract Optional method, called when the MovinPositioner can no longer determine your position, because you are no
 * longer in the supported venue.
 */
-(void)positioningEngineDidFindUnknownLocation:(nonnull MovinPositioner*)engine;
@end

// Inline callback delegate
@interface InlineMovinPositioningListener : NSObject <MovinPositioningListener>
-(nonnull id) initWithInitializedBlock:(nullable void (^)(BOOL success, NSError* _Nullable error)) initializedBlock
       andUpdatedPositionBlock:(nullable void (^)(FloorPosition* _Nonnull position)) updatedPositionBlock
        andLostConnectionBlock:(nullable void (^)()) lostConnectionBlock
       andUnknownLocationBlock:(nullable void (^)()) unknownLocationBlock;
@end