//
//  AB.h
//  DLActivateTester
//
//  Created by TehranSlippers on 7/16/15.
//  Copyright © 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCommon.h"
#include "ABObserver.h"
#import "ABRouting.h"
#import "ABRequestOperation.h"
#import "ABRequestOperationWorker.h"
#import "ABAppIndexing.h"
#import "ABAttribution.h"
#import "ABConstants.h"
#import "ABNetworkRequestFormatter.h"

@protocol ABTrackingDelegate <NSObject>

@optional
- (void)airbridgeUserAttributed:(ABAttribution *)attribution;

@end

@interface AirBridge : NSObject

@property (strong, nonatomic) ABAppIndexing *appIndexingManager;
@property (strong, nonatomic) ABAttribution *abAttribution;
@property (strong, nonatomic) ABRequestOperationWorker *abOperationWorker;

@property (weak) id<ABTrackingDelegate> airbridgeTrackingDelegate;

+ (BOOL) stopAirBridgeTracking ;
+ (AirBridge*)instance;

/**
 * init method for airbridge
 *
 * @param appToken SDK에서 사용할 앱 토큰을 넣어주세요. (대시보드에서 확인하실 수 있습니다)
 * @param appName appName를 넣어주세요.
 * @return AirBridge instance
 */
+ (AirBridge *)getInstance:(NSString *)appToken appName:(NSString *)appName;
+ (AirBridge *)getInstance:(NSString *)appToken appName:(NSString *)appName facebookSDKInstalled:(BOOL)fbSet;
+ (AirBridge *)getInstance:(NSString *)appToken appName:(NSString *)appName withLaunchOptions:(NSDictionary *)launchOptions;
+ (AirBridge *)getInstance:(NSString *)appToken appName:(NSString *)appName withLaunchOptions:(NSDictionary *)launchOptions facebookSDKInstalled:(BOOL)fbSet;

+ (BOOL)setupWithAppToken:(NSString *)appToken appName:(NSString *)appName;
+ (void)initInstance:(NSString *)appToken appName:(NSString *)appName facebookSDKInstalled:(BOOL)fbSet ;

- (void)handleURL:(NSURL *)url;
- (BOOL)canHandleURL:(NSURL *)url;
- (BOOL)setDeeplink:(NSURL *)url;

- (void)install;

- (BOOL)launch:(NSDictionary *)params;
- (void)launchWithOptions:(NSDictionary *)options;

- (void)registDefaultRoutingCallback:(abDefaultRoutingCallback)callback;
- (void)registSimpleLinkRoutingCallback:(abSimpleLinkRoutingCallback)callback;

- (void)registRouting:(NSString *)routeString callback:(abAutoRoutingCallback)callback;
- (void)registRouting:(NSString *)routeString description:(NSString *)desc callback:(abAutoRoutingCallback)callback;

- (BOOL)goalWithCategory:(NSString *)category;
- (BOOL)goalWithCategory:(NSString *)category customAttributes:(NSDictionary *)customAttributes;
- (BOOL)goalWithCategory:(NSString *)category action:(NSString *)action label:(NSString *)label value:(NSNumber *)value customAttributes:(NSDictionary *)customAttributes;

- (void)setUser:(NSString *)userID;
- (void)setEmail:(NSString *)userEmail;

- (BOOL)setCurrentTracingViewWithLabel:(NSString *)label;
- (BOOL)setCurrentTracingViewWithLabel:(NSString *)label name:(NSString *)name customAttributes:(NSDictionary *)customAttributes;

- (void)noticeAppIndexingScheme:(ABAppindexingScheme)scheme;
- (void)noticeAppIndexingSchemes:(NSArray *)schemes;

- (void)createAppIndexingWith:(NSString *)identifier title:(NSString *)title description:(NSString *)description;

- (NSString *)getSavedIFV ;
- (NSString *)getSavedIDFA ;
- (NSString *)getMobileUUID ;

- (void)setPreviousActiveStatus:(NSNumber *)activeStatus;
- (NSNumber*) getPreviousActiveStatus;

/**
    Control 3rd party integrations
 **/
- (BOOL)turnOnAppboyIntegration __deprecated_msg("use - (void)fetchUserAttributedDelegate: instead.");
- (void)fetchUserAttributedDelegate:(ABAttribution *)attribution;

/**
    Set facebook SDK options
 **/
- (void)turnOnFacebookSDKInstalled:(BOOL)set;
- (void)setFacebookDeferredApplinkWithURL:(NSURL *)fbDeferredApplink;


/**
    Handling Log Manager
 **/
+ (BOOL)showDebugConsole;
+ (void)setDebugConsoleLevel:(ABLogType)logType;

//[2017.10.24][Stone] //다른 인터페이스에서 네트워크 작업 요청할 수 있도록 함.
- (void)addRequestOperation:(NSString *)path requestFormatter:(ABNetworkRequestFormatter *)rqFormatter methodType:(ABNetworkingType)methodType requestName:(NSString *)requestName;
/**
 {
 @identifier: [NSString] <required>
 @title: [NSString] <required>
 @description: [NSString] <required>
 @userInfo : [NSDictionary]
 @keywords : [NSSet]
 @thumbnail : [UIImage]
 @expireDate : [NSDate]
 }
 **/
- (void)createAppIndexingWith:(NSDictionary*)indexDataDictionary;
- (void)deleteAppIndexing:(NSString*)identifier;
- (void)deleteAppIndexingWithIdentifiers:(NSArray*)identifiers;

//- (void)sendBackgroundActionToQueue;
//- (void)sendForegroundActionToQueue;

- (void)resetInstallSessionToken;

#pragma mark - Session
-(void) setCustomSessionTimeOut:(NSInteger)secTimeout;
#pragma mark - Wifi
- (void) setWifiInfoUsability:(BOOL)enable; //default: false

#pragma mark - depracated methods
+ (AirBridge *)getInstance:(NSString*)userToken appToken:(NSString*)appToken __deprecated_msg("use - (AirBridge *)getInstance:appName: instead");
+ (AirBridge *)getInstance:(NSString*)userToken appToken:(NSString*)appToken facebookSDKInstalled:(BOOL)fbSet __deprecated_msg("use - (AirBridge *)getInstance:appName:facebookSDKInstalled: instead");
+ (AirBridge *)getInstance:(NSString*)userToken appToken:(NSString*)appToken withLaunchOptions:(NSDictionary *)launchOptions __deprecated_msg("use - (AirBridge *)getInstance:appName:withLaunchOptions: instead");
+ (AirBridge *)getInstance:(NSString*)userToken appToken:(NSString*)appToken withLaunchOptions:(NSDictionary *)launchOptions facebookSDKInstalled:(BOOL)fbSet __deprecated_msg("use - (AirBridge *)getInstance:appName:withLaunchOptions:facebookSDKInstalled: instead");

- (BOOL)userSignup:(NSString*)value __deprecated_msg("use - (BOOL)userSignupWithEmail:andID: instead.");
- (BOOL)userSignin:(NSString*)value __deprecated_msg("use - (BOOL)userSigninWithEmail:andID: instead.");

- (BOOL)userSignupWithEmail:(NSString *)email andID:(NSString *)idx __deprecated_msg("This method will be deprecated. Use ABUserEvent Module instead. ( - (BOOL)sendSignup )");
- (BOOL)userSigninWithEmail:(NSString *)email andID:(NSString *)idx __deprecated_msg("This method will be deprecated. Use ABUserEvent Module instead. ( - (BOOL)sendSignin )");

- (BOOL)addItemToCart:(NSDictionary *)customAttributes __deprecated_msg("This method will be deprecated. Use ABEcommerceEvent Module instead. ( - (BOOL) sendAddProductToCart )");
- (BOOL)purchased:(NSNumber *)value currency:(NSString *)currency __deprecated_msg("This method will be deprecated. Use ABEcommerceEvent Module instead. ( - (BOOL) sendCompleteOrder )");

- (BOOL)goalWithDescription:(NSString *)goalDescription __deprecated_msg("use - (BOOL)simpleGoalWithCategory: instead.");
- (BOOL)goalWithDescription:(NSString *)goalDescription category:(NSString*)category __deprecated_msg("use - (BOOL)simpleGoalWithCategory:customAttributes: instead.");
- (BOOL)goalWithDescription:(NSString *)goalDescription key:(NSString*)goalKey __deprecated_msg("use - (BOOL)simpleGoalWithCategory:customAttributes: instead.");
- (BOOL)goalWithDescription:(NSString *)goalDescription category:(NSString*)category key:(NSString*)goalKey __deprecated_msg("use - (BOOL)simpleGoalWithCategory:customAttributes: instead.");

- (BOOL)simpleGoalWithDescription:(NSString *)goalDescription __deprecated_msg("use - (BOOL)simpleGoalWithCategory: instead.");
- (BOOL)simpleGoalWithDescription:(NSString *)goalDescription category:(NSString*)category __deprecated_msg("use - (BOOL)simpleGoalWithCategory:customAttributes: instead.");
- (BOOL)simpleGoalWithDescription:(NSString *)goalDescription key:(NSString*)goalKey __deprecated_msg("use - (BOOL)simpleGoalWithCategory:customAttributes: instead.");
- (BOOL)simpleGoalWithDescription:(NSString *)goalDescription category:(NSString*)category key:(NSString*)goalKey __deprecated_msg("use - (BOOL)simpleGoalWithCategory:customAttributes: instead.");

- (BOOL)setCurrentTracingView:(NSString*)viewName __deprecated_msg("use - (BOOL)setCurrentTracingViewWithLabel: instead.");
- (BOOL)setCurrentTracingView:(NSString*)viewName userInfo:(NSDictionary*)userInfo __deprecated_msg("use - (BOOL)setCurrentTracingViewWithLabel:name:customAttributes: instead.");
- (BOOL)setCurrentTracingAction:(NSString*)actionName __deprecated_msg("");
- (BOOL)setCurrentTracingAction:(NSString*)actionName userInfo:(NSDictionary*)userInfo __deprecated_msg("");

@end
