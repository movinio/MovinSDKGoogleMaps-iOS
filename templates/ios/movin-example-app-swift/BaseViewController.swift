//
//  BaseViewController.swift
//  movin-example-app-swift
//
//  Created by Tim Potze on 18/07/16.
//  Copyright © 2016 Movin. All rights reserved.
//

import UIKit

class BaseViewController: UIViewController {
    func alert(title: String, message: String, canClose: Bool) {
        func showMessage() -> () {
            let alert = UIAlertController(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)

            if canClose {
                let ok = UIAlertAction(title: "OK", style: UIAlertActionStyle.default) {
                    (action) -> () in
                    alert.dismiss(animated: true, completion: nil)
                }

                alert.addAction(ok)
            }

            self.present(alert, animated: true, completion: nil)
        }

        if Thread.isMainThread {
            showMessage();
        } else {
            DispatchQueue.main.async(execute: showMessage)
        }
    }
}
