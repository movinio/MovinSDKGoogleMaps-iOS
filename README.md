# MovinSDKGoogleMaps-iOS
This repository contains the static iOS library of the Google Maps integration for the MovinSDK.

Demo
----
To try out the MovinSDK with Google Maps integration, follow these steps:
- Install CoacoaPods: [CocoaPods Guids - Getting Started](https://guides.cocoapods.org/using/getting-started.html).
- Run the command `pod try MovinSDKGoogleMaps` in your Terminal. This will open XCode with our example project.
  - If you prefer to use Swift:
    - Expand the `movin-example-app-swift` project in your XCode Navigator.
    - In `AppDelegate.swift`, insert your own Google Maps API key in the call to `GMSServices.provideAPIKey` and remove the `_ERROR` line above it. [Get API Key - Google Maps iOS SDK Documentation](https://developers.google.com/maps/documentation/ios-sdk/get-api-key)
    - In `InitViewController.swift`, insert your Movin customer name, API key and map name into the `movinCustomer`, `movinAPIKey` and `movinMapName` variables and remove the `_ERROR` line above it. You can find these values in your Movin portal.
  - If you prefer to use Objective-C:
    - Expand the `movin-example-app` project in your XCode Navigator.
    - In `AppDelegate.m`, insert your own Google Maps API key in the call to `[GMSServices provideAPIKey:]` and remove the `#error` line above it. [Get API Key - Google Maps iOS SDK Documentation](https://developers.google.com/maps/documentation/ios-sdk/get-api-key)
    - In `InitViewController.m`, insert your Movin customer name, API key and map name into the `movinCustomer`, `movinAPIKey` and `movinMapName` variables and remove the `#error` line above it. You can find these values in your Movin portal.
 
If you have any questions, feel free to contact us at info@movin.io.

License
-------
Licensed under Creative Commons Attribution-NoDerivs 3.0 Unported

<p>
THE WORK (AS DEFINED BELOW) IS PROVIDED UNDER THE TERMS OF THIS CREATIVE COMMONS PUBLIC LICENSE ("CCPL" OR "LICENSE"). THE WORK IS PROTECTED BY COPYRIGHT AND/OR OTHER APPLICABLE LAW. ANY USE OF THE WORK OTHER THAN AS AUTHORIZED UNDER THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.

BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED HERE, YOU ACCEPT AND AGREE TO BE BOUND BY THE TERMS OF THIS LICENSE. TO THE EXTENT THIS LICENSE MAY BE CONSIDERED TO BE A CONTRACT, THE LICENSOR GRANTS YOU THE RIGHTS CONTAINED HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF SUCH TERMS AND CONDITIONS.
</p>

You may obtain copy of the license at https://creativecommons.org/licenses/by-nd/3.0/legalcode
