//
//  BaseViewController.h
//  movin-example-app
//
//  Created by Tim Potze on 28/06/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BaseViewController : UIViewController

/**
 * @abstract A helper method which creates an UIAlertController with an UIAlertControllerStyleAlert style with
 * the specified title and message.
 * @param title The title of the alert.
 * @param message The message of the alert.
 * @param canClose A value which indicates whether the alert can be closed.
 */
- (void)alertWithTitle:(NSString*)title
            andMessage:(NSString*)message
           andCanClose:(BOOL)canClose;
@end

