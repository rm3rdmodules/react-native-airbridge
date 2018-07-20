//
//  ABCommon.h
//  DLActivateTester
//
//  Created by TehranSlippers on 7/16/15.
//  Copyright © 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AB_VERSION @"M_I_v1.3.7"

typedef NS_ENUM(NSUInteger, ABAppindexingScheme) {
    ABAPPIDXING_RESTAURANT,
    ABAPPIDXING_MUSIC
};

@interface ABCommon : NSObject

+ (void)setUserDefaultSuiteName:(NSString *)suiteName;
+ (NSUserDefaults *)getUserDefaults;

+ (BOOL)debugMode;
+ (BOOL)isShowDebugConsole;
+ (BOOL)showDebugConsole:(BOOL)set;
+ (BOOL)isDefalutNetworkingToSync;
+ (BOOL)defalutNetworkingToSync:(BOOL)set;
+ (BOOL)resetAirBridgeSDK;

+ (void)wrtieObjectToUserDefaultWith:(NSObject*)object key:(NSString*)key;
+ (NSString*)makeUniqueID;

+ (void)setSession:(NSString*)token ;

+ (void)setAppToken:(NSString*)token ;
+ (NSString*)getAppToken;

+ (void)setAppName:(NSString*)appName ;
+ (NSString*)getAppName;
+ (BOOL)isSetAppName;
/*
 * 15.12.23 Donutt: IDFA not used in ver 0.2.1 under , 
 * this will be used in after ~~ version.
 */

+ (void)setAirBridgeCanonicalUserId:(NSString*)cUserId;
+ (NSString*)getAirBridgeCanonicalUserId;

+ (void)setAirBridgeUUID:(NSString*)UUID ;
+ (NSString*)getAirBridgeUUID;
+ (NSString*)getSession;
+ (NSString*)getFingerprint;
+ (NSDictionary*)getFingerprintToDictionary;


+ (void)setSimpleLinkTokenWith:(NSString*)token ;
+ (NSString *)getSimpleLinkToken;

// storing control
+ (void)saveObject:(id)object toFile:(NSString *)filename;
+ (id)objectFromFile:(NSString *)filename;
+ (NSString *)pathWithFilename:(NSString *)filename;

#pragma mark -
#pragma mark deprecated features
+ (void)setAirBridgeIDFA:(NSString*)IDFA ;
+ (NSString*)getAirBridgeIDFA;

// storing attribution values
+ (void)setAirBridgeAttributionSource:(NSString*)source ;
+ (NSString*)getAirBridgeAttributionSource;
+ (void)setAirBridgeAttributionCampaign:(NSString*)campaign ;
+ (NSString*)getAirBridgeAttributionCampaign;
+ (void)setAirBridgeAttributionAdgroup:(NSString*)adgroup ;
+ (NSString*)getAirBridgeAttributionAdgroup;
+ (void)setAirBridgeAttributionAdcreative:(NSString*)adcreative ;
+ (NSString*)getAirBridgeAttributionAdcreative;

+ (void)setAirBridgeAttributionMedium:(NSString*)medium ;
+ (NSString*)getAirBridgeAttributionMedium;
+ (void)setAirBridgeAttributionSearchKeyword:(NSString*)searchkeyword ;
+ (NSString*)getAirBridgeAttributionSearchKeyword;
+ (void)setAirBridgeAttributionSearchAdContent:(NSString*)adContent;
+ (NSString*)getAirBridgeAttributionAdContent;

+ (void)setAirBridgeAttributionFinished;
+ (BOOL)getAirBridgeAttributionFinished;

+ (void)setDebugNetworkMode:(BOOL)isDebug;
+ (NSString*)md5SHA256FromString:(NSString*)originalString;
@end

#ifdef DEBUG
#define ABLog(fmt, ...) NSLog((@"[AB] %s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define ABLog(...)
#endif

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)
