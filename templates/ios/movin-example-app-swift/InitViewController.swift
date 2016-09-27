//
//  InitViewController.swift
//  movin-example-app-swift
//
//  Created by Tim Potze on 18/07/16.
//  Copyright © 2016 Movin. All rights reserved.
//

import UIKit

class InitViewController: BaseViewController {
    override func viewDidLoad() {
        super.viewDidLoad()

        _ERROR("Insert your Movin customer name and API key in the variables below and delete this line.")
        let movinCustomer = "<your-customer-name-here>"
        let movinAPIKey = "<your-api-key-here>"
        let movinMapName = "<your-map-name-here>"

        MovinSDK.initWithCustomer(movinCustomer, andApikey: movinAPIKey) {
            (success: Bool, error: Error?) -> Void in
            /*
             * This callback will be invoked once the initialization has been completed. The success value
             * will hold YES if the initialization has been successful or NO otherwise. The initialization
             * may succeed even without a live internet connection if the initialization has been completed
             * before and caching has not been turned off (on by default). The error value will hold an
             * NSError instance with information about the failure if the initialization has failed.
             */
            if success {
                /*
                 * If the initialization was successful, find the map this app should operate with. Store
                 * this map in the AppDelegate instance of this app.
                 */
                do {
                    // Find the map with the name specified in movinMapName.
                    let map = (try MovinSDK.getMaps()).filter() {
                        (map: MovinMap) -> Bool in
                        return map.name == movinMapName
                    }.first

                    if map == nil {
                        self.alert(title: "Initialization failure",  message: "Could not load map", canClose:false)
                        return
                    }

                    // Store the map in the AppDelegate instance of this app.
                    let delegate = UIApplication.shared.delegate as! AppDelegate
                    delegate.map = map

                    /*
                     * Once the initialization has been completed successfully, perform a seague to the map view.
                     * The seague must be performed on the main queue and this block may be executed on
                     * another queue.
                     */
                    DispatchQueue.main.async {
                        self.performSegue(withIdentifier: "InitializedSeague", sender:self)
                    }
                } catch let err as NSError {
                    self.alert(title: "Initialization failure",  message: err.localizedDescription, canClose:false)
                }
            } else {
                self.alert(title: "Initialization failure",  message: error!.localizedDescription, canClose:false)
            }
        }
    }
}

