//
//  AnalyticsService.h
//  MovinSDK
//
//  Created by Movin Software on 16/10/15.
//  Copyright © 2015 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AnalyticsService : NSObject

/**
 * @abstract Gets the number of updates which still need to be sent to the server.
 */
@property(readonly) NSUInteger pendingUpdates;
/**
 * @abstract Returns the shared instance of the AnalyticsService, or nil if the state is false
 */
+ (nullable AnalyticsService*)instance;

/**
 * @abstract provides the AnalyticsID through the given callback. When the AnalyticsService is still busy with initializing, the callback is called once it is finished, otherwise it will be called immediately.
 * @param callback The callback to invoke once the AnalyticsService knows the AnalyticsID
 */
- (void)getAnalyticsIdWithCallback:(nullable void (^)(NSString* _Nullable analyticsId, NSError* _Nullable error))callback;

/**
 * @abstract Sends all remaining updates to the server.
 */
-(void)flushPendingUpdates;
@end
