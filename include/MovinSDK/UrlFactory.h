//
//  UrlFactory.h
//  MovinCore
//
//  Created by Movin Software on 31/03/15.
//  Copyright (c) 2015 Movin Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MovinMap;
@class FloorPosition;
@class BeaconIdentifier;

@interface UrlFactory : NSObject
// Setters
+ (void)setCustomer:(NSString*)customer;

+ (void)setHostName:(NSString*)hostName;

+ (void)setApikey:(NSString*)apikey;

+ (void)setUseHttps:(BOOL)useHttps;


// Core
+ (NSString*)getBaseURL;

+ (NSString*)getAvailableServicesURL;

// Data
+ (NSString*)getMapsUrlWithBuildings:(BOOL)buildings
                         andEntities:(BOOL)entities;

+ (NSString*)getMapUrlForMap:(MovinMap*)map
                andBuildings:(BOOL)buildings
                 andEntities:(BOOL)entities;

+ (NSString*)getBeaconGroupsURLForMap:(MovinMap*)map
                           andBeacons:(BOOL)beacons;

+ (NSString*)updateShuffledIdsURL;

+ (NSString*)updateShuffledIdsPostDataForBeacons:(NSDictionary<BeaconIdentifier*, BeaconIdentifier*>*)shuffledIds;

// Positioning
+ (NSString*)getPositioningUuidsURLForMap:(MovinMap*)map;

+ (NSString*)getPositionURL;

+ (NSString*)getPositioningDatabaseURLForMap:(MovinMap*)map;

+ (NSString*)getPositioningDatabaseVersionURLForMap:(MovinMap*)map;

// WMTS
+ (NSString*)getTileUrlWithLayer:(NSString*)layer
                        andStyle:(NSString*)style
                            andX:(int)x
                            andY:(int)y
                         andZoom:(int)zoom
                        andFloor:(double)floor;

+ (NSString*)getTilesPackageWithMap:(MovinMap*)map
                           andLayer:(NSString*)layer
                           andStyle:(NSString*)style
                           andFloor:(double)floor;

+ (NSString*)getTilesPackageManifestUrlWithMap:(MovinMap*)map;

// Routing
+ (NSString*)getRouteUrlFromPosition:(FloorPosition*)fromPos
                          toPosition:(FloorPosition*)toPos;

// Analytics
+ (NSString*)createAssetURL;

+ (NSString*)createAssetPostDataWithOsVersion:(NSString*)osVersion
                               andDeviceModel:(NSString*)model;

+ (NSString*)addAssetPositionPostDataWithAssetId:(NSString*)assetId
                                     andPosition:(FloorPosition*)position;

+ (NSString*)getAssetURLWithAssetId:(NSString*)assetId;

+ (NSString*)addMultipleAssetPositionURL;
@end
