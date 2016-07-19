//
// Created by Tim Potze on 15/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MovinFeatureObject.h"

@class GeoShape;
@class MovinBuilding;
@class MovinEntitySubType;

@interface MovinEntity : MovinFeatureObject
/**
 * @abstract Gets the building this instance is a member of.
 */
@property(readonly, nullable, weak) MovinBuilding* building;
/**
 * @abstract Gets the floor number of this instance.
 */
@property(readonly) double floor;
/**
 * @abstract Gets the sub type of this instance.
 */
@property(readonly, nonnull) MovinEntitySubType* subType;

/**
 * @abstract Initializes a new MovinEntity object with the specified building and JSON data.
 * @param building The building the entity is a member of.
 * @param json The JSON data.
 * @return A MovinMap object with the specified building and JSON data.
 */
- (nonnull id)initWithBuilding:(nonnull MovinBuilding*)building andJson:(nonnull NSDictionary*)json;

@end