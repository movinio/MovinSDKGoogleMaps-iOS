Pod::Spec.new do |s|
  s.name         = "MovinSDKGoogleMaps"
  s.version      = "2.7.0"
  s.summary      = "Static iOS library of the Google Maps integration for the MovinSDK."
  s.description  = <<-DESC
This repository contains the static iOS library of the Google Maps integration for the MovinSDK.
                   DESC

  s.homepage     = "http://www.movin.io"
  s.license      = { :type => 'CC BY-ND 3.0', :file => 'LICENSE' }
  s.author       = { "Movin " => "info@movin.io" }

  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/movinio/MovinSDKGoogleMaps-iOS.git", :tag => s.version.to_s }
  s.source_files  = "include/**/*.h"
  s.public_header_files = "include/**/*.h"

  s.preserve_paths = "libMovinSDKGoogleMaps.a"
  s.ios.vendored_library = "libMovinSDKGoogleMaps.a"


  s.dependency "GoogleMaps"
  s.dependency "MovinSDK"

  s.libraries = "c++", "z"
  s.frameworks = "ImageIO", "CoreMotion", "SystemConfiguration", "CoreLocation", "UIKit"

  s.requires_arc = true
end
