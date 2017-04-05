//
// MovinGMSImageRendererManager.h
// MovinSDKGoogleMaps
//
// Copyright © 2017 Movin. All rights reserved.
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
@property (weak) id<MovinGMSImageRendererManagerDelegate> delegate;
/**
 * Gets all renders registered to this image renderer manager.
 */
@property (readonly) NSArray<MovinGMSImageRenderer*>* allRenderers;

/**
 * Refreshes the visible entities.
 */
- (void)refreshEntities;

/**
 * Returns the image renderer associated with the specified overlay.
 *
 * @param overlay The overlay to get the image renderer of.
 * @return The associated image renderer.
 */
- (MovinGMSImageRenderer*)getImageRendererForOverlay:(GMSOverlay*)overlay;

/**
 * Returns the image renderer associated with the specified entity.
 *
 * @param entity The entity to get the image renderer of.
 * @return The associated image renderer.
 */
- (MovinGMSImageRenderer*)getImageRendererForEntity:(MovinEntity*)entity;
@end