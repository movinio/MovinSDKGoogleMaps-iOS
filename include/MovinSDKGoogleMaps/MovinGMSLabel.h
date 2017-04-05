//
// MovinGMSLabel.h
// MovinSDKGoogleMaps
//
// Copyright © 2017 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MovinSDK/MovinSDK.h>
#import "MovinGMSImageRenderer.h"

@class MovinGMSMapView;

/**
 * Represents a label which can be drawn on a MovinGSMSMapView.
 */
@interface MovinGMSLabel : MovinGMSImageRenderer
/**
 * Gets or sets the text which will be drawn on this label.
 */
@property (nonnull) NSString* text;
/**
 * Gets or sets the font in which the text will be drawn. The default value is "Arial 30".
 */
@property (nonnull) UIFont* font;
/**
 * Gets or sets the text color in which the text will be drawn. The default value is black.
 */
@property (nonnull) UIColor* textColor;
/**
 * Gets or sets the halo color with which the text will be drawn. The default value is white.
 */
@property (nonnull) UIColor* textHaloColor;
/**
 * Gets or sets the halo width. The default value is 1.0.
 */
@property float textHaloWidth;

/**
 * Initializes a new MovinGMSLabel object with the specified map, position, floor and bounds.
 *
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
 * Initializes a new MovinGMSLabel object with the specified map, position, floor, bearing and bounds.
 *
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