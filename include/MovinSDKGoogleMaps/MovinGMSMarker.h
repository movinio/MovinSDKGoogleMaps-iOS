//
// MovinGMSMarker.h
// MovinSDKGoogleMaps
//
// Copyright © 2017 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MovinGMSImageRenderer.h"

/**
 * Represents a marker image which can be drawn on a MovinGMSMapView.
 */
@interface MovinGMSMarker : MovinGMSImageRenderer
/**
 * Initializes a new MovinGMSMarker object with the specified map view, position, floor and bearing.
 *
 * @param map The map view in which to render the marker.
 * @param position The position of the marker.
 * @param floor The floor on which the marker should be drawn.
 * @param bearing The bearing with which the marker should  be drawn.
 * @return A MovinGMSMarker object with the specified map view, position, floor and bearing.
 */
-(id)initWithMap:(MovinGMSMapView*)map
     andPosition:(GeoLatLng*)position
        andFloor:(double)floor
      andBearing:(float)bearing;

/**
 * Gets or sets the scale if the image.
 */
@property double imageScale;
/**
 * Gets or sets the image displayed at the location of this marker.
 */
@property UIImage* image;
@end