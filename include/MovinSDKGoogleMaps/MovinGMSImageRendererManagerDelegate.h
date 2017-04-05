//
// MovinGMSImageRendererManagerDelegate.h
// MovinSDKGoogleMaps
//
// Copyright © 2017 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MovinSDK/MovinSDK.h>

@class MovinGMSImageRendererManager;

/**
 * Defines methods that a delegate of APIRequest must implement to be able to determine which entities should
 * automatically be drawn on the map.
 */
@protocol MovinGMSImageRendererManagerDelegate<NSObject>

@optional

/**
 * Returns a value indicating whether the image renderer manager should create a renderer for the specified
 * entity.
 *
 * @param manager The image renderer manager.
 * @param entity The entity for which to decide whether an image renderer should be created.
 * @return YES if an image renderer should be created; NO otherwise.
 */
- (BOOL)imageRendererManager:(MovinGMSImageRendererManager*)manager
          shouldRenderEntity:(MovinEntity*)entity;

/**
 * Occurs when image renderers have been loaded for the entities for the active style.
 *
 * @param manager  The image renderer manager.
 */
- (void)imageRendererManagerDidLoadImageRenderers:(MovinGMSImageRendererManager*)manager;
@end