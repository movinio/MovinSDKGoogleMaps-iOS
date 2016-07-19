//
//  MovinMap.h
//  libMovinSDK
//
//  Created by Tim Potze on 03/03/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MovinFeatureObject.h"

@class MovinEntitySubType;
@class MovinPositioningEngine;
@class GeoShape;
@class MovinBeacon;
@class MovinBeaconGroup;
@class MovinEntity;
@class MovinBuilding;
@class MovinTileProvider;
@class MovinTileManifest;

typedef void(^DownloadDataCallback)(BOOL success, NSError* _Nullable error);
typedef void(^BeaconGroupsCallback)(NSArray<MovinBeaconGroup*>* _Nullable beaconGroups, NSError* _Nullable error);
typedef void(^BeaconsCallback)(NSArray<MovinBeacon*>* _Nullable beacons, NSError* _Nullable error);
typedef void(^BuildingsCallback)(NSArray<MovinBuilding*>* _Nullable buildings, NSError* _Nullable error);
typedef void(^EntitiesCallback)(NSArray<MovinEntity*>* _Nullable entities, NSError* _Nullable error);
typedef void(^TileManifestCallback)(MovinTileManifest* _Nullable tileManifest, NSError* _Nullable error);

@interface MovinMap : MovinFeatureObject

/**
 * @abstract Gets the description of this map.
 */
@property(readonly, nonnull) NSString* descriptionText;
/**
 * @abstract Gets the lowest floor number of this map.
 */
@property(readonly) double lowestFloorNumber;
/**
 * @abstract Gets the highest floor number of this map.
 */
@property(readonly) double highestFloorNumber;

/**
 * @abstract Gets an dictionary filled with the sub types available in this map.
 */
@property(readonly, nonnull) NSDictionary<NSString*, MovinEntitySubType*>* subTypes;
/**
 * @abstract Gets whether or not the map is currently downloading map data
 */
@property(readonly) BOOL isDownloadingMapData;
/**
 * @abstract Gets whether or not the map is currently downloading beacon data
 */
@property(readonly) BOOL isDownloadingBeaconData;

/**
 * @abstract Initializes a new MovinMap object with the specified JSON data.
 * @param json The JSON data.
 * @return A MovinMap object with the specified JSON data.
 */
- (nonnull id)initWithJson:(nonnull NSDictionary*)json;

/**
 * @abstract Attempts to create a positioning engine. If it succeeds, a MovinPositioningEngine is returned, otherwise
 * the given NSError pointer points to the NSError describing what went wrong.
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return The MovinPositioningEngine for this map or nil if an error occurred.
 * @code NSError* error = nil;
 MovinPositioningEngine* positioningEngine = [movinMap getPositioningEngine:&error];
 if(error != nil) {
    NSLog(@"An error occurred when getting a MovinPositioningEngine: %@", [error localizedDescription]);
 } else {
    // positioningEngine != nil
    NSLog(@"Succesfully created a MovinPositioningEngine");
 }
 */
- (nullable MovinPositioningEngine*)getPositioningEngine:(NSError* _Nullable* _Nullable)error;

/**
 * @abstract Attempts to download the beacon data. After downloading the data the callback, if present, will be invoked.
 * If the data has already been loaded the callback will be invoked immediately.
 * @param callback The callback to invoke once the downloading has been completed.
 */
- (void)downloadBeaconDataWithCallback:(nullable DownloadDataCallback)callback;

/**
 * @abstract Attempts to download the map data. After downloading the data the callback, if present, will be invoked.
 * If the data has already been loaded the callback will be invoked immediately.
 * @param callback The callback to invoke once the downloading has been completed.
 */
- (void)downloadMapDataWithCallback:(nullable DownloadDataCallback)callback;

/**
 * @abstract Attempts to download the tile manifest. After downloading the file the callback, if present, will be
 * invoked. If the manifest has already been loaded the callback will be invoked immediately.
 * @param callback The callback to invoke once the downloading has been completed.
 */
- (void)downloadTileManifestWithCallback:(nullable DownloadDataCallback)callback;

/**
 * @abstract Caches all image data associated with the sub types, map data and beacons.
 */
- (void)downloadImageData;

/**
 * @abstract Gets all beacons available in this map. The result is returned using a callback.
 * @param callback The callback to invoke once the result is ready.
 */
- (void)getBeaconsWithCallback:(nonnull BeaconsCallback)callback;

/**
 * @abstract Gets all beacon groups available in this map. The result is returned using a callback.
 * @param callback The callback to invoke once the result is ready.
 */
- (void)getBeaconGroupsWithCallback:(nonnull BeaconGroupsCallback)callback;

/**
 * @abstract Gets all beacons in this map within the specified shape and floor. The result is returned using a callback.
 * @param shape The shape in which to search.
 * @param floor The floor on which to search.
 * @param callback The callback to invoke once the result is ready.
 */
- (void)getBeaconsInShape:(nonnull GeoShape*)shape
                 andFloor:(double)floor
              andCallback:(nonnull BeaconsCallback)callback;

/**
 * @abstract Gets all entities available in this map. The result is returned using a callback.
 * @param callback The callback to invoke once the result is ready.
 */
- (void)getEntitiesWithCallback:(nonnull EntitiesCallback)callback;

/**
 * @abstract Gets all entities in this map within the specified shape and floor. The result is returned using a callback.
 * @param shape The shape in which to search.
 * @param floor The floor on which to search.
 * @param callback The callback to invoke once the result is ready.
 */
- (void)getEntitiesInShape:(nonnull GeoShape*)shape
                  andFloor:(double)floor
               andCallback:(nonnull EntitiesCallback)callback;

/**
 * @abstract Gets all buildings available in this map. The result is returned using a callback.
 * @param callback The callback to invoke once the result is ready.
 */
- (void)getBuildingsWithCallback:(nonnull BuildingsCallback)callback;

/**
 * @abstract Gets all buildings in this map within the specified shape. The result is returned using a callback.
 * @param shape The shape in which to search.
 * @param callback The callback to invoke once the result is ready.
 */
- (void)getBuildingsInShape:(nonnull GeoShape*)shape
                andCallback:(nonnull BuildingsCallback)callback;

/**
 * @abstract Gets the tile manifest for this map. The result is returned using a callback.
 * @param callback The callback to invoke once the result is ready.
 */
- (void)getTileManifestWithCallback:(nonnull TileManifestCallback)callback;
@end
