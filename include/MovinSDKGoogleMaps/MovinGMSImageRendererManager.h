//
// Created by Tim Potze on 29/08/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MovinGMSImageRenderer;
@class GeoAABB;
@class MovinMap;
@class MovinGMSMapView;
@protocol MovinGMSImageRendererManagerDelegate;

/**
 * @class MovinGMSImageRendererManager
 * @brief Manages the hiding, showing and drawing of MovinGMSImageRenderer instances.
 */
@interface MovinGMSImageRendererManager : NSObject

/**
 * @brief Gets or sets whether entities should automatically be loaded onto the map.
 */
@property BOOL loadEntities;
/**
 * @brief Gets or sets the delegate of this image renderer manager.
 */
@property id<MovinGMSImageRendererManagerDelegate> delegate;
/**
 * @brief Refreshes the visible entities.
 */
- (void) refreshEntities;
@end