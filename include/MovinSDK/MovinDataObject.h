//
// Created by Tim Potze on 20/04/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MovinDataObject : NSObject
/**
 * @abstract Gets the identity of this instance.
 */
@property(readonly, nonnull) NSString* id;
/**
 * @abstract Gets the name of this instance.
 */
@property(readonly, nullable) NSString* name;

/**
 * @abstract Gets a collection of properties of this instance.
 */
@property(readonly, nonnull) NSDictionary* properties;

/**
 * @abstract Initializes a new MovinDataObject object with the specified JSON data.
 * @param json The JSON data.
 * @return A MovinDataObject object with the specified JSON data.
 */
- (nonnull id)initWithJson:(nonnull NSDictionary*)json;

/**
 * @abstract Initializes a new MovinDataObject object with the specified JSON data and properties.
 * @param json The JSON data.
 * @param properties The properties of the instance.
 * @return A MovinDataObject object with the specified JSON data and properties.
 */
- (nonnull id)initWithJson:(nonnull NSDictionary*)json
              andProperties:(nonnull NSDictionary*)properties;

/**
 * @abstract Sets a callback which can be invoked to determine which image files should be downloaded and cached for the
 * specified property key.
 * @code [building setCacheableImageExtractorForKey:@"buildingImage" andCallback: ^(NSString* value){
 *            NSArray* result;
 *            if([[value substringToIndex:4] isEqualToString:@"http"]) {
 *                result = @[value];
 *            }
 *            return result;
 *        }];
 */
- (void)setCacheableImageExtractorForKey:(nonnull NSString*)key
                             andCallback:(nonnull NSArray<NSString*>* _Nullable (^)(id _Nonnull value))callback;
@end