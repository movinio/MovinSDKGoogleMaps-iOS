//
//  AppDelegate.h
//  movin-example-app
//
//  Created by Tim Potze on 28/06/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MovinSDK/MovinSDK.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (nonatomic) MovinMap* map;


@end

