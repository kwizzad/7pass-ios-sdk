#
# Be sure to run `pod lib lint SevenPass.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "SevenPassSDK"
  s.version          = "1.0.2"
  s.summary          = "7Pass SDK to access 7Pass SSO features"

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!
  s.description      = <<-DESC
    7Pass iOS SDK is a Swift library for interacting with the 7Pass SSO service.
                       DESC

  s.homepage         = "https://github.com/p7s1-ctf/7pass-ios-sdk"
  # s.screenshots     = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "Jan Votava" => "jan@sensible.io" }
  s.source           = { :git => "https://github.com/p7s1-ctf/7pass-ios-sdk.git", :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.platform     = :ios, '8.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes/**/*'
  s.resource_bundles = {
    'SevenPass' => ['Pod/Assets/*.png']
  }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'

  # s.dependency 'OAuthSwift@p7s1', '~> 0.5.0p1'
  s.dependency 'CryptoSwift'
  s.dependency 'Locksmith'
  s.dependency 'JWTDecode', '~> 1.0'
  s.dependency 'AwesomeCache', '~> 2.0'
  s.dependency 'JSONWebToken'

  s.ios.vendored_frameworks = 'Carthage/Build/iOS/OAuthSwift.framework'
end