//
//  InitViewController.m
//  movin-example-app
//
//  Created by Tim Potze on 28/06/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import "InitViewController.h"
#import "AppDelegate.h"
#import <MovinSDK/MovinSDK.h>

@interface InitViewController ()

@end

@implementation InitViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    #error Insert your Movin customer name and API key in the variables below and delete this #error line.
    NSString* movinCustomer = @"<your-customer-name-here>";
    NSString* movinAPIKey = @"<your-api-key-here>";
    NSString* movinMapName = @"<your-map-name-here>";

    /*
     * Initialize the MovinSDK with your customer name and API key.
     */
    [MovinSDK initWithCustomer:movinCustomer andApikey:movinAPIKey
                   andCallback:^(BOOL success, NSError* _Nullable error) {
                       /*
                        * This callback will be invoked once the initialization has been completed. The success value
                        * will hold YES if the initialization has been successful or NO otherwise. The initialization
                        * may succeed even without a live internet connection if the initialization has been completed
                        * before and caching has not been turned off (on by default). The error value will hold an
                        * NSError instance with information about the failure if the initialization has failed.
                        */
                       if (success) {
                           /*
                            * If the initialization was successful, find the map this app should operate with. Store
                            * this map in the AppDelegate instance of this app.
                            */
                           NSError* err = nil;

                           // Find the map with the name specified in movinMapName.
                           MovinMap* map = [[MovinSDK getMaps:&err] filteredArrayUsingPredicate:
                                   [NSPredicate predicateWithFormat:@"%K = %@", @"name", movinMapName]].firstObject;

                           // Check for errors and a result value. If a problem has occurred, display an alert with
                           // the error message.
                           if (err != nil) {
                               [self alertWithTitle:@"Initialization failure"
                                         andMessage:err.localizedDescription
                                        andCanClose:NO];
                               return;
                           }

                           if (map == nil) {
                               [self alertWithTitle:@"Initialization failure"
                                         andMessage:@"Could not load map"
                                        andCanClose:NO];
                               return;
                           }

                           // Store the map in the AppDelegate instance of this app.
                           AppDelegate* delegate = (AppDelegate*)UIApplication.sharedApplication.delegate;
                           delegate.map = map;

                           /*
                            * Once the initialization has been completed successfully, perform a seague to the map view.
                            * The seague must be performed on the main queue and this block may be executed on
                            * another queue.
                            */
                           dispatch_async(dispatch_get_main_queue(), ^{
                               [self performSegueWithIdentifier:@"InitializedSeague" sender:self];
                           });
                       } else {
                           /*
                            * If the initialization has failed, display an alert with the description of the error which
                            * has occurred during the initialization.
                            */
                           [self alertWithTitle:@"Initialization failure"
                                     andMessage:error.localizedDescription
                                    andCanClose:NO];
                       }
                   }];

}

@end
