//
// Created by Tim Potze on 16/08/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MovinSDK/MovinSDK.h>
#import "MovinGMSImageRenderer.h"

@class MovinGMSMapView;

/**
 * @class MovinGMSLabel
 * @brief Represents a label which can be drawn on a MovinGSMSMapView.
 */
@interface MovinGMSLabel : MovinGMSImageRenderer
/**
 * @brief Gets or sets the text which will be drawn on this label.
 */
@property (nonnull) NSString* text;
/**
 * @brief Gets or sets the font in which the text will be drawn. The default value is "Arial 30".
 */
@property (nonnull) UIFont* font;
/**
 * @brief Gets or sets the text color in which the text will be drawn. The default value is black.
 */
@property (nonnull) UIColor* textColor;
/**
 * @brief Gets or sets the halo color with which the text will be drawn. The default value is white.
 */
@property (nonnull) UIColor* textHaloColor;
/**
 * @brief Gets or sets the halo width. The default value is 1.0.
 */
@property float textHaloWidth;

/**
 * @brief Initializes a new MovinGMSLabel object with the specified map, position, floor and bounds.
 * @param map The map to draw the label on.
 * @param position The position to draw the label to.
 * @param floor The floor to draw the label on.
 * @param bounds The bounds to draw the label in.
 * @return A MovinGMSLabel object with the specified map, position, floor and bounds.
 */
- (nonnull id)initWithMap:(nonnull MovinGMSMapView*)map
              andPosition:(nonnull GeoLatLng*)position
                 andFloor:(double)floor
                andBounds:(nonnull GeoShape*)bounds;

/**
 * @brief Initializes a new MovinGMSLabel object with the specified map, position, floor, bearing and bounds.
 * @param map The map to draw the label on.
 * @param position The position to draw the label to.
 * @param floor The floor to draw the label on.
 * @param bearing The bearing with which the label will be drawn.
 * @param bounds The bounds to draw the label in.
 * @return A MovinGMSLabel object with the specified map, position, floor, bearing and bounds.
 */
- (nonnull id)initWithMap:(nonnull MovinGMSMapView*)map
              andPosition:(nonnull GeoLatLng*)position
                 andFloor:(double)floor
               andBearing:(float)bearing
                andBounds:(nonnull GeoShape*)bounds;
@end