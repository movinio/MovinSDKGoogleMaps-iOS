//
//  MovinFloorSwitcher.h
//  MovinSDK
//
//  Created by Tim Potze on 25/04/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MovinTileProvider;

@interface MovinFloorSwitcher : UIView
/**
 * @abstract Gets or sets the background color of the current floor indicator and the floor switcher button.
 */
@property UIColor* focusedBackgroundColor;
/**
 * @abstract Gets or sets the font color of the current floor.
 */
@property UIColor* focusedForegroundColor;
/**
 * @abstract Gets or sets the background color of the floors list.
 */
@property UIColor* unfocusedBackgroundColor;
/**
 * @abstract Gets or sets the font color of floors in the floors list.
 */
@property UIColor* unfocusedForegroundColor;
/**
 * @abstract Gets or sets the font used within the floor switcher.
 */
@property UIFont* font;
/**
 * @abstract Gets or sets the maximum height of the floor switcher.
 */
@property float maxHeight;
/**
 * @abstract Gets or sets the height of every item in the floors list.
 */
@property float itemHeight;
/**
 * @abstract Gets or sets the corner radius of the floor switcher.
 */
@property float cornerRadius;
/**
 * @abstract Gets or sets the margin between the floor switcher button and the floors list.
 */
@property float margin;

/**
 * @abstract Gets or sets the duration of the floors list.
 */
@property float animationDuration;

/**
 * @abstract Gets or sets the tile provider this instance will switch the floor of.
 */
@property MovinTileProvider* tileProvider;

/**
 * @abstract Gets or sets a value indicating whether the floors list is visible (YES) or hidden (NO).
 */
@property BOOL isOpen;

/**
 * @abstract Initializes a new MovinFloorSwitcher object with the specified tile provider.
 * @param tileProvider The tile provider to switch the floor of.
 * @return A MovinFloorSwitcher object with the specified tile provider.
 */
- (id)initWithTileProvider:(MovinTileProvider*)tileProvider;
@end
