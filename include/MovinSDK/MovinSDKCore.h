//
//  MovinSDK.m
//  MovinSDK
//
//  Created by Movin Software on 26/04/15.
//  Copyright (c) 2015 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MovinCacheProtocol;
@class MovinMap;
@class MovinBeaconScanner;

/**
 * @typedef MovinService
 * @abstract A list of the Movin services.
 */
typedef enum {
    /// Undefined
    MovinServiceUndefined = 0,
    /// Positioning
    MovinServicePositioning = 1,
    /// Turn by turn
    MovinServiceTurnByTurn = 2,
    /// Proximity
    MovinServiceProximity = 4,
    /// Trigger
    MovinServiceTrigger = 8,
    /// Routing
    MovinServiceRouting = 16,
    /// Data
    MovinServiceData = 32
} MovinService;

/**
 * @typedef MovinCacheableData
 * @abstact A list of Movin data types which can be cached.
 */
typedef enum {
    /// Data used by the MovinPositioningEngine.
    MovinCacheableDataPositioning = 1,
    /// Data provided by MovinMap, such as buildings and entities.
    MovinCacheableDataMapData = 2,
    // Tiles provided by the MovinTileProvider.
    MovinCacheableDataTiles = 4,
    // Images provided by the MovinImageProvider.
    MovinCacheableDataImages = 8,
    // Data used by the MovinRoutingManager.
    MovinCacheableDataRouting = 16,
    // Beacon data provided by MovinMap and used by MovinBeaconScanner.
    MovinCacheableDataBeacons = 32,

    // All cachable data types
    MovinCacheableDataAll = 63
} MovinCacheableData;

@interface MovinSDK : NSObject
/**
 * @abstract Initializes the MovinSDK, which validates the given customer and apikey. The device will be checked for compatibility with Bluetooth Low Energy and some primary components are initialized.
 * @param customer The customer name, provided by Movin
 * @param apikey The apikey associated with this customer, either provided by Movin or generated in the Movin portal
 * @param callback The block called once the initialization finished. Provides a boolean whether it has succeeded and if it has not succeeded an NSError containing the error which occurred.
 * @code [MovinSDK initWithCustomer:@"<customer_name>"
                  andApikey:@"<apikey>"
                andCallback:^(BOOL success, NSError* error) {
    if(success) {
        NSLog(@"Succesfully initialized the SDK!");
    } else {
        NSLog(@"Error initializing the SDK: %@", [error localizedDescription]);
    }
 }];
 */
+(void) initWithCustomer:(nonnull NSString *)customer
               andApikey:(nonnull NSString *)apikey
             andCallback:(nullable void (^)(BOOL success, NSError* _Nullable error))callback;

/**
 * @abstract Uninitializes the MovinSDK.
 */
+(void)reset;

// Constructors
/**
 * @abstract Returns the singleton instance of MovinBeaconScanner.
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred. An error may occur if the SDK has not yet been initialized.
 * @return The singleton instance of MovinBeaconScanner
 */
+(nullable MovinBeaconScanner*) getBeaconScanner:(NSError* _Nullable * _Nullable) error;

// Maps
/**
 * @abstract Returns a collection of available maps.
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return A collection of available maps.
 */
+(nullable NSArray<MovinMap*>*) getMaps: (NSError* _Nullable * _Nullable) error;

/**
 * @abstract Returns a MovinMap object with the specified id. If the specified id is not available an error is set.
 * @param id The identifier of the map.
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return A MovinMap object with the specified id. If the specified id is not available an error is set.
 */
+(nullable MovinMap*) getMapWithId: (nonnull NSString *)id andError: (NSError* _Nullable * _Nullable) error;

// Status getters
/**
 * @abstract Returns whether or not the MovinSDK has already been initialized or not.
 */
+(BOOL) isInitialized;

/**
 * @abstract Checks if the given service is supported by both the device and apikey rights.
 * @param service The service to check for.
 * @return Whether or not the service is supported.
 */
+(BOOL) getServiceSupported:(MovinService) service;

// Caching
///**
// * @abstract Clears the cached files stored by the Movin SDK.
// */
+(void) clearCache;

/**
 * @abstract Sets the cache protocol for the specified data types.
 * @param types The types for which to set the cache protocol.
 * @param to The cache protocol.
 * @warning This method can only be used when the SDK has not yet been initialized.
 * @code [MovinSDK setCacheProtocolForTypes:MovinCacheableDataPositioning|MovinCacheableDataMapData [MovinCacheProtocol default]]
 */
+(void) setCacheProtocolForTypes: (MovinCacheableData) types to: (nonnull MovinCacheProtocol*)cacheProtocol;

/**
 * @abstract Gets a value indicating whether caching has been enabled fo the specified data type.
 * @return Whether or not caching has been enabled for the specified data type.
 */
+(nonnull MovinCacheProtocol*)getCacheProtocolForType: (MovinCacheableData) type;

/**
 * @abstract Sets a value indicating whether the analytics service should be enabled.
 * @param toggle A value indicating whether the analytics service should be enabled.
 */
+(void)setAnalyticsEnabled:(BOOL)toggle;

/**
 * @abstract Returns the version number of the Movin SDK.
 * @return The version number of the Movin SDK.
 */
+(unsigned int)getVersion;

/**
 * @abstract Returns the version string of the Movin SDK.
 * @return The version string of the Movin SDK.
 */
+(nonnull NSString*)getVersionString;
@end
