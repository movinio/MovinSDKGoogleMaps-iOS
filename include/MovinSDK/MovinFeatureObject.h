//
// Created by Tim Potze on 20/04/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MovinDataObject.h"

@class GeoShape;


@interface MovinFeatureObject : MovinDataObject
/**
 * @abstract Gets the geometric shape of this instance.
 */
@property(nonnull, readonly) GeoShape* geometry;

/**
 * @abstract Initializes a new MovinFeatureObject object with the specified JSON data.
 * @param json The JSON data.
 * @return A MovinFeatureObject object with the specified JSON data.
 */
- (nonnull id)initWithJson:(nonnull NSDictionary*)json;
@end