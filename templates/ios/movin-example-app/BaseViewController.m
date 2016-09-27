//
//  BaseViewController.m
//  movin-example-app
//
//  Created by Tim Potze on 28/06/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import "BaseViewController.h"

@implementation BaseViewController

// A helper method which creates an UIAlertController with an UIAlertControllerStyleAlert style with the specified
// title and message.
- (void)alertWithTitle:(NSString*)title
            andMessage:(NSString*)message
           andCanClose:(BOOL)canClose {

    // This block will be executed on the main thread.
    void (^showMessage)() = ^{
        // Create the alert controller.
        UIAlertController* alert = [UIAlertController alertControllerWithTitle:title
                                                                       message:message
                                                                preferredStyle:UIAlertControllerStyleAlert];

        // Add a single action to the alert controller if the alert can be closed, the OK button.
        if(canClose) {
            UIAlertAction* ok = [UIAlertAction
                    actionWithTitle:@"OK"
                              style:UIAlertActionStyleDefault
                            handler:^(UIAlertAction* action) {
                                [alert dismissViewControllerAnimated:YES completion:nil];
                            }];

            [alert addAction:ok];
        }
        // Present the alert.
        [self presentViewController:alert animated:YES completion:nil];
    };

    if ([NSThread isMainThread]) {
        showMessage();
    }
    else {
        dispatch_sync(dispatch_get_main_queue(), showMessage);
    }
}

@end
