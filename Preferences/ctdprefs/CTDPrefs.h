// Umbrella header for CTDPrefs.
// Add import lines for each public header, like this: #import
// <CTDPrefs/XXXAwesomeClass.h> Don’t forget to also add them to
// CTDPrefs_PUBLIC_HEADERS in your Makefile!

#import <UIKit/UIKit.h>
#import <Preferences/PSHeaderFooterView.h>
#import <Preferences/PSListController.h>
#import <Preferences/PSSpecifier.h>
#import <Preferences/PSTableCell.h>

@interface UIColor (APIFix)
+ (UIColor *)secondarySystemGroupedBackgroundColor; // iOS 13+
@end

@interface CTDHeaderCell : PSTableCell <PSHeaderFooterView>
@property (nonatomic, retain) UILabel *titleLabel;
@property (nonatomic, retain) UILabel *subtitleLabel;
@property (nonatomic, retain) UIImageView *iconView;
@property (nonatomic, retain) UIStackView *containerStackView;
@property (nonatomic, retain) UIView *backgroundView;
@end

@interface CTDPreferenceSettings : NSObject
@property (nonatomic) BOOL customizeNavbar;
@property (nonatomic, strong) UIColor *barTintColor;
@property (nonatomic, strong) UIColor *tintColor;
@property (nonatomic) BOOL forceLight;

+ (instancetype)sharedInstance;
- (id)init;
@end

@interface CTDListController : PSListController
@property (nonatomic, strong) CTDPreferenceSettings *preferenceSettings;
@end

@interface CTDTableCell : PSTableCell
@end

#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
