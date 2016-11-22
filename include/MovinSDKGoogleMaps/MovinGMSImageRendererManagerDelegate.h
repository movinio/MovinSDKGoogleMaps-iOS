//
// Created by Tim Potze on 31/10/2016.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MovinSDK/MovinSDK.h>

@class MovinGMSImageRendererManager;

/**
 * Defines methods that a delegate of APIRequest must implement to be able to determine which entities should
 * automatically be drawn on the map.
 */
@protocol MovinGMSImageRendererManagerDelegate<NSObject>

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
@end