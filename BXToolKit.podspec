#
# Be sure to run `pod lib lint BXToolKit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
s.name             = 'BXToolKit'
s.version          = '0.0.3'
s.summary          = '封装了一些常用的工具类'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

s.description      = <<-DESC
TODO: Add long description of the pod here.
DESC

s.homepage         = 'https://github.com/xudusheng/BXToolKit'
# s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
s.license          = { :type => 'MIT', :file => 'LICENSE' }
s.author           = { 'xudusheng' => 'xudusheng@bisinuolan.com' }
s.source           = { :git => 'https://github.com/xudusheng/BXToolKit.git', :tag => s.version.to_s }
# s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

s.ios.deployment_target = '8.0'

s.subspec 'Foundation' do |foundation|
foundation.source_files = 'BXToolKit/Classes/Foundation/**/*'
end

s.subspec 'UIKit' do |ui|
ui.source_files = 'BXToolKit/Classes/UIKit/**/*'
ui.dependency 'BXToolKit/Foundation'
end

s.subspec 'DataTool' do |data|
data.source_files = 'BXToolKit/Classes/DataTool/**/*'
data.dependency 'BXToolKit/UIKit'
end

end
