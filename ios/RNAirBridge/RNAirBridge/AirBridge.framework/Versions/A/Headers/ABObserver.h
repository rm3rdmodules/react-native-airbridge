//
//  ABObserver.h
//  UdlSDKSample
//
//  Created by TehranSlippers on 7/30/15.
//  Copyright (c) 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ABCommon.h"


@interface ABObserver : NSObject

//+(NSString *)getSettingLanguage;
+ (NSString *)getAppURLScheme;
+ (NSString *)getBundleIdentifier;

+ (NSString *)getDeviceType;
+ (NSString *)getDeviceIdentifier;

+ (NSString *)getAppVersion;
+ (NSString *)getSDKVersion;
+ (NSString *)getOSVersionReturnNumber;
+ (NSString *)getOSVersion;
+ (CGSize)getScreenSize;
+ (NSString *)getSystemLocale;
+ (NSString *)getSystemTimezone;
+ (NSString *)getApplicationOrientation;

+ (NSString *)getIDFA;
+ (NSString *)getIFV;
+ (NSString *)getUniqueHardwareId:(BOOL *)isReal andIsDebug:(BOOL)debug;
+ (BOOL)isAdTrackingEnable;

+ (NSString *)getIPAddress:(BOOL)preferIPv4;
+ (NSInteger)getNetworkStatus;

+ (NSDictionary*)getWifiInfo;
+(void) setSendingWifiInfoEnable:(BOOL)enable;

+ (NSNumber *)getCurrentUnixms ;


@end
