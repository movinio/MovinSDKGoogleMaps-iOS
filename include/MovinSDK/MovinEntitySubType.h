//
// Created by Tim Potze on 03/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MovinDataObject.h"

@class GeoLatLng;
@class MovinImagePoint;


@class UIImage;

@interface MovinEntitySubType : MovinDataObject
/**
 * @abstract Gets the base type of this sub type.
 */
@property(readonly, nonnull) NSString* baseType;
/**
 * @abstract Gets the description of this sub type.
 */
@property(readonly, nullable) NSString* descriptionText;
/**
 * @abstract Gets the point of interest image URL of this sub type.
 */
@property(readonly, nullable) NSString* poiUrl;
/**
 * @abstract Gets the anchor location of the point of interest image specified in poiUrl. The x and y values range between 0.0 and 1.0.
 */
@property(readonly, nullable) MovinImagePoint* poiAnchor;
/**
 * @abstract Gets the size of the point of interest image specified in poiUrl.
 */
@property(readonly, nullable) MovinImagePoint* poiSize;

/**
 * @abstract Initializes a new MovinEntitySubType object with the specified JSON data.
 * @param json The JSON data.
 * @return A MovinEntitySubType object with the specified JSON data.
 */
- (nonnull id)initWithJson:(nonnull NSDictionary*)json;

/**
 * @abstract Returns the POI image of this sub type.
 * @param callback The callback which will be invoked once the POI image has been downloaded.
 */
- (void)getPoiImage:(nonnull void(^)(UIImage* _Nullable image, NSError* _Nullable error))callback;
@end