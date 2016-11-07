//
//  MovinGMSImageRenderer.h
//  TestDrawingLabels
//
//  Created by Tim Potze on 15/08/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GoogleMaps/GoogleMaps.h>
#import <MovinSDK/MovinSDK.h>

@class MovinGMSMapView;

/**
 * @class MovinGMSImageRenderer
 * @brief Represents an object which can be drawn on a MovinGMSMapView.
 */
@interface MovinGMSImageRenderer : NSObject

/**
 * @brief Gets or sets the map this image renderer should draw on.
 */
@property MovinGMSMapView* map;
/**
 * @brief Gets or sets the position where the image should be drawn to.
 */
@property GeoLatLng* position;
/**
 * @brief Gets or sets the floor the image should be drawn on.
 */
@property double floor;
/**
 * @brief Gets the image which will be drawn.
 */
@property(readonly) UIImage* image;
/**
 * @brief Gets or sets the bearing of the image.
 */
@property float bearing;
/**
 * @brief Gets or sets the bounds in which the image should be drawn.
 */
@property GeoShape* bounds;
/**
 * @brief Gets or sets the scaling style of the image.
 */
@property MovinTileStyleScaling scaling;
/**
 * @brief Gets or sets the rotation style of the image.
 */
@property MovinTileStyleRotation rotation;
/**
 * @brief Gets or sets the size of a pixel in meters on zoom level 0.
 */
@property float metersPerPixel;
/**
 * @brief Gets or sets the zoom level at which the sizing is based when the sizingStyle is set to
 * MovinGMSSizingStyleFixed.
 */
@property float fixedZoomLevel;
/**
 * @brief Gets or sets the minimum zoom level from which the image is visible.
 */
@property float minZoomLevel;
/**
 * @brief Gets or sets the maximum zoom level to which the image is visible.
 */
@property float maxZoomLevel;

/**
 * @brief Gets or sets the opacity of the image.
 */
@property float opacity;

/**
 * @brief Gets or sets the anchor point of the image.
 */
@property CGPoint anchor;

/**
 * @brief Gets a value indicating whether this element is visible.
 */
@property(readonly) BOOL visible;

/**
 * @brief Gets the size of the image.
 */
@property(readonly) CGSize imageSize;

/**
 * @brief Gets the size the image should have on a GMSGroundOverlay.
 */
@property(readonly) CGSize overlaySize;

/**
 * @brief Gets the bearing the image should have on a GMSGroundOverlay.
 */
@property(readonly) double overlayBearing;

/**
 * @brief Invalidates the image of this instance and requests the image to be re-rendered. This method should only
 * every be called by subclasses of MovinGMSImageRenderer.
 */
- (void)invalidate;

/**
 * @brief This method is called by the invalidation process when a new image should be rendered. This method should
 * be overridden by subclasses of MovinGMSImageRenderer and should not be called by any class other than
 * MovinGMSImageRenderer.
 */
- (void)renderImage:(void (^)(UIImage*))responder;

@end
