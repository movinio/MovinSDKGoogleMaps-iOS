//
// Created by Tim Potze on 08/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface MovinCacheProtocol : NSObject
/**
 * @abstract Gets a value indicating whether caching is allowed according to this caching protocol.
 */
@property(readonly) BOOL allowCaching;
/**
 * @abstract Gets a value indicating whether the cache should be synced after it has been downloaded for the first time.
 */
@property(readonly) BOOL allowSyncing;
/**
 * @abstract Gets the refresh rate of the cache. After the interval specified by this refresh rate the cache
 * will be synchronized with the server. A value of 0 will ensure the cache is being synchronized every time the SDK is
 * being initialized. If no Wi-Fi connection is available the cache will only be synchronized if the forced refresh rate
 * has elapsed as well.
 */
@property(readonly) NSTimeInterval refreshRate;
/**
 * @abstract Gets the forced refresh of the cache. If the interval specified by refreshRate has passed but
 * no Wi-Fi connection is available, the cache will still be synchronized if the forced refresh interval has passed.
 * A value of 0 will never allow syncing over WWAN (Mobile Data) at all.
 */
@property(readonly) NSTimeInterval forcedRefreshRate;
/**
 * @abstract Gets the timeout interval for requests sent out while an expired cached version of the response is available.
 */
@property(readonly) NSTimeInterval timeoutWithAvailableCache;
/**
 * @abstract Gets the timeout interval for request sent out while no cached version of the response is available.
 */
@property(readonly) NSTimeInterval timeout;
/**
 * @abstract Provides a human readable description of the cache protocol.
 */
@property(readonly) NSString* description;

/**
 * @abstract Initializes a new MovinCacheProtocol object with the specified caching options.
 * @param allowCaching A value indicating whether caching is allowed according to this caching protocol.
 * @param allowSyncing A value indicating whether the cache should be synced after it has been downloaded for the first
 * time.
 * @param refreshRate The refresh rate of the cache. After the interval specified by this refresh rate the cache
 * will be synchronized with the server. A value of 0 will ensure the cache is being synchronized every time the SDK is
 * being initialized. If no Wi-Fi connection is available the cache will only be synchronized if the forced refresh rate
 * has elapsed as well.
 * @param forcedRefreshRate The forced refresh of the cache. If the interval specified by refreshRate has passed but
 * no Wi-Fi connection is available, the cache will still be synchronized if the forced refresh interval has passed.
 * A value of 0 will disable this functionality.
 * @param timeoutWithAvailableCache The timeout interval for requests sent out while an expired cached version of the
 * response is available.
 * @param timeout The timeout interval for request sent out while no cached version of the response is available.
 * @return A MovinCacheProtocol object with the specified caching options.
 */
- (id)  initWithAllowCaching:(BOOL)allowCaching
             andAllowSyncing:(BOOL)allowSyncing
              andRefreshRate:(NSTimeInterval)refreshRate
        andForcedRefreshRate:(NSTimeInterval)forcedRefreshRate
andtimeoutWithAvailableCache:(NSTimeInterval)timeoutWithAvailableCache
                  andTimeout:(NSTimeInterval)timeout;

/**
 * @abstract A default cache protocol. This protocol allows caching and does not limit syncing to Wi-Fi. The
 * refresh rate is set to 0 meaning the cache will be synced at every startup. The timeout for requests with available
 * cache is set to 10 seconds. Requests without a cached response available is set to 60 seconds.
 */
+ (MovinCacheProtocol*)standard;

/**
 * @abstract A do-not-cache cache protocol. This protocol does not allow any caching to occur. The timeout is set to
 * 60 seconds.
 */
+ (MovinCacheProtocol*)doNotCache;

/**
 * @abstract Returns a copy of this instance with allowCaching set to the specified value.
 * @param allowCaching A value indicating whether caching is allowed according to this caching protocol.
 * @return A copy of this instance with allowCaching set to the specified value.
 */
- (MovinCacheProtocol*)withAllowCaching:(BOOL)allowCaching;

/**
 * @abstract Returns a copy of this instance with allowSyncing set to the specified value.
 * @param allowSyncing A value indicating whether the cache should be synced after it has been downloaded for the first time.
 * @return A copy of this instance with allowSyncing set to the specified value.
 */
- (MovinCacheProtocol*)withAllowSyncing:(BOOL)allowSyncing;

/**
 * @abstract Returns a copy of this instance with refreshRate set to the specified value.
 * @param refreshRate The refresh rate of the cache. After the interval specified by this refresh rate the cache
 * will be synchronized with the server. A value of 0 will ensure the cache is being synchronized every time the SDK is
 * being initialized. If no Wi-Fi connection is available the cache will only be synchronized if the forced refresh rate
 * has elapsed as well.
 * @return A copy of this instance with refreshRate set to the specified value.
 */
- (MovinCacheProtocol*)withRefreshRate:(NSTimeInterval)refreshRate;

/**
 * @abstract Returns a copy of this instance with forcedRefreshRate set to the specified value.
 * @param forcedRefreshRate The forced refresh of the cache. If the interval specified by refreshRate has passed but
 * no Wi-Fi connection is available, the cache will still be synchronized if the forced refresh interval has passed.
 * A value of 0 will disable this functionality.
 * @return A copy of this instance with forcedRefreshRate set to the specified value.
 */
- (MovinCacheProtocol*)withForcedRefreshRate:(NSTimeInterval)forcedRefreshRate;
/**
 * @abstract Returns a copy of this instance with timeout set to the specified value
 * @param timeout The timeout interval for request sent out while no cached version of the response is available.
 * @return A copy of this instance with timeout set to the specified value.
 */
- (MovinCacheProtocol*)withTimeout:(NSTimeInterval)timeout;
/**
 * @abstract Returns a copy of this instance with timeoutWithAvailableCache set to the specified value
 * @param timeout Tte timeout interval for requests sent out while an expired cached version of the response is available.
 * @return A copy of this instance with timeoutWithAvailableCache set to the specified value.
 */
- (MovinCacheProtocol*)withTimeoutWithAvailableCache:(NSTimeInterval)timeoutWithAvailableCache;

/**
 * @abstract Returns a value indicating whether the cache should be synced based on the specified time since last synchronization.
 * @param timeSinceLastSync The time since the last synchronization.
 * @return A value indicating whether the cache should be synced based on the specified time since last synchronization.
 */
- (BOOL)shouldReadFromCache:(NSTimeInterval)timeSinceLastSync;
@end