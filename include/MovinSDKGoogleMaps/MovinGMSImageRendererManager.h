//
// MovinGMSImageRendererManager.h
// MovinSDKGoogleMaps
//
// Copyright © 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MovinGMSImageRenderer;
@class GeoAABB;
@class MovinMap;
@class MovinGMSMapView;
@protocol MovinGMSImageRendererManagerDelegate;

/**
 * Manages the hiding, showing and drawing of MovinGMSImageRenderer instances.
 */
@interface MovinGMSImageRendererManager : NSObject

/**
 * Gets or sets whether entities should automatically be loaded onto the map.
 */
@property BOOL loadEntities;
/**
 * Gets or sets the delegate of this image renderer manager.
 */
@property id<MovinGMSImageRendererManagerDelegate> delegate;
/**
 * Refreshes the visible entities.
 */
- (void) refreshEntities;
@end