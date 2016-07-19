//
//  MovinBeaconScanner.h
//  libMovinSDK
//
//  Created by Movin Software on 07/03/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MovinMap;
@class MovinBeacon;
@class MovinRangedBeacon;
@class MovinBeaconScanner;

@protocol MovinBeaconScannerListener <NSObject>
@optional
/**
 * @abstract Method is called when the user entered the area for the provided UUID. This method is only called when background scanning is active and the CLAuthorizationStatus equals kCLAuthorizationStatusAuthorizedAlways.
 * @param uuid The iBeacon ProximityUUID of the area that was entered.
 */
-(void)beaconScanner:(nonnull MovinBeaconScanner*) scanner didEnterAreaWithUUID:(nonnull NSUUID*) uuid;

/**
 * @abstract Method is called when the user exited the area for the provided UUID. This method is only called when background scanning is active and the CLAuthorizationStatus equals kCLAuthorizationStatusAuthorizedAlways.
 * @param uuid The iBeacon ProximityUUID of the area that was exited.
 */
-(void)beaconScanner:(nonnull MovinBeaconScanner*) scanner didExitAreaWithUUID:(nonnull NSUUID*) uuid;

/**
 * @abstract Is called when the nearest beacon is changed or when the current nearest beacon is out of range.
 * @param beacon The new nearest beacon, or nil if the current nearest beacon is out of range.
 */
-(void)beaconScanner:(nonnull MovinBeaconScanner*) scanner didChangeNearestBeacon:(nullable MovinRangedBeacon*) beacon;
/**
 * @abstract When this method is implemented the onNearestBeaconChanged method only returns beacons that pass this method.
 * @param beacon The beacon that needs to be validated.
 * @return Whether the beacon is valid for the onNearestBeaconChanged result.
 */
-(BOOL)beaconScanner:(nonnull MovinBeaconScanner*) scanner isValidNearestBeacon:(nonnull MovinRangedBeacon*) beacon;

/**
 * @abstract Is called when beacons are ranged.
 * @param beacons The beacons that were ranged.
 */
-(void)beaconScanner:(nonnull MovinBeaconScanner*) scanner didRangeBeacons:(nonnull NSArray<MovinRangedBeacon*>*) beacons;
@end



@interface MovinBeaconScanner : NSObject
/**
 * @abstract Adds a map to the MovinBeaconScanner to scan for. The UUID's of the beacons in the map are neccesary to start scanning. The beacons found in the MovinMap will automatically be connected to the ranged beacons.
 * @param map The MovinMap of which the beacons should be scanned for.
 */
-(void) addMap:(nonnull MovinMap*)map;
/**
 * @abstract Adds a map to the MovinBeaconScanner to scan for. The UUID's of the beacons in the map are neccesary to start scanning. The beacons found in the MovinMap will automatically be connected to the ranged beacons. To this method a callback is given, which will be informed once the map was succesfully added or not. If the map has succesfully retrieved its beacon data, but in the meantime the map was removed from the MovinBeaconScanner, the listener will not be called.
 * @param map The MovinMap of which the beacons should be scanned for.
 * @param listener A listener block that will be informed if the beacons of the map were be succesfully added or not.
 */
-(void) addMap:(nonnull MovinMap*)map withSuccessListener:(nullable void(^)(BOOL success, NSError* _Nullable error)) listener;
/**
 * @abstract Removes a map from the MovinBeaconScanner, the UUID's only found in this map will no longer be scanned for. Beacons found in this MovinMap will no longer be automattically connected to the ranged beacons.
 * @param map The MovinMap of which the beacons no longer should be scanned for.
 */
-(void) removeMap:(nonnull MovinMap*)map;

/**
 * @abstract Starts the MovinBeaconScanner and calls the given listener. Only the first time this method is called the internal MovinLocationManager will be started.
 * @param listener The listener that will receive the events.
 */
-(void) startWithListener:(nonnull id<MovinBeaconScannerListener>) listener;
/**
 * @abstract Stops the MovinBeaconScanner for the given listener. Only when no more listeners remain this method will actually stop the MovinLocationManager.
 * @param listener The listener that will no longer receive events.
 */
-(void) stopWithListener:(nonnull id<MovinBeaconScannerListener>) listener;

/**
 * @abstract Adds a silent listener which will be informed of its implemented events. Adding such a listener will not affect whether or not the MovinBeaconScanner starts or stops.
 * @param listener The listener to add.
 */
-(void) addSilentListener:(nonnull id<MovinBeaconScannerListener>) listener;
/**
 * @abstract Removes a silent listener. Removing such a listener will not affect whether or not the MovinBeaconScanner starts or stops.
 * @param listener The listener to remove.
 */
-(void) removeSilentListener:(nonnull id<MovinBeaconScannerListener>) listener;

/**
 * @abstract Sets background scanning enabled. To enable background scanning (ranging), Apple requires that also regular location updates are started using startUpdatingLocation. To waste as little battery as possible, the CLLocationAccuracy will be set to 3km, and the distance filter is set to 100000000m. The default background enabled value is false.
 * @warning When using background scanning enabled, the appropriate background mode needs to be enabled (background mode location). Also the NSAlwaysUsageDescription should be set in the info.plist and method [CLLocationManager requestAlwaysAuthorization]; must be granted for this to work.
 * @warning When submitting an app that uses backround scanning, you have to presuade the reviewers that your app actually needs background scanning, since it consumes more power than apple would like.
 */
-(void) setBackgroundEnabled:(BOOL) enabled;
/**
 * @abstract Gets the background enabled value.
 * @return The background enabled value.
 */
-(BOOL) getBackgroundEnabled;

@end
