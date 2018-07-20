//
//  ABNetworking.h
//  DLActivateTester
//
//  Created by TehranSlippers on 7/16/15.
//  Copyright © 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "ABCookieMatcher.h"

typedef void (^ABNetworkingSuccessBlock)(id json);
typedef void (^ABNetworkingFailBlock)(NSError *error, id json);
typedef void (^ABNetworkingRetryBlock)(NSInteger retryCount);

typedef NS_ENUM(NSUInteger, ABNetworkingType) {
    ABNETWORKING_TYPE_GET,
    ABNETWORKING_TYPE_POST,
    ABNETWORKING_TYPE_GET_SYNC,
    ABNETWORKING_TYPE_POST_SYNC
};

@interface ABNetworking : NSObject

@property (nonatomic, assign) NSInteger backoffCounter;

+ (void)requestWithType:(ABNetworkingType)type
                   path:(NSString*)path
             parameters:(NSDictionary *)parameters
           successBlock:(ABNetworkingSuccessBlock)successBlock
              failBlock:(ABNetworkingFailBlock)failBlock;

+ (void)getToPath:(NSString *)path
       parameters:(NSDictionary *)parameters
     successBlock:(ABNetworkingSuccessBlock)successBlock
        failBlock:(ABNetworkingFailBlock)failBlock;

+ (void)postToPath:(NSString *)path
        parameters:(NSDictionary *)parameters
      successBlock:(ABNetworkingSuccessBlock)successBlock
         failBlock:(ABNetworkingFailBlock)failBlock;

+ (void)getSyncToPath:(NSString *)path
           parameters:(NSDictionary *)parameters
         successBlock:(ABNetworkingSuccessBlock)successBlock
            failBlock:(ABNetworkingFailBlock)failBlock;

+ (void)postSyncToPath:(NSString *)path
            parameters:(NSDictionary *)parameters
          successBlock:(ABNetworkingSuccessBlock)successBlock
             failBlock:(ABNetworkingFailBlock)failBlock;


+ (void)installWithPath:(NSString *)path
             parameters:(NSDictionary *)parameters
           successBlock:(ABNetworkingSuccessBlock)successBlock
             retryBlock:(ABNetworkingRetryBlock)retryBlock
              failBlock:(ABNetworkingFailBlock)failBlock;

+ (void)installWithPath:(NSString *)path
                headers:(NSDictionary *)headers
             parameters:(NSDictionary *)parameters
           successBlock:(ABNetworkingSuccessBlock)successBlock
             retryBlock:(ABNetworkingRetryBlock)retryBlock
              failBlock:(ABNetworkingFailBlock)failBlock;

+ (void)setDeeplinkWithPath:(NSString *)path
                 parameters:(NSDictionary *)parameters
               successBlock:(ABNetworkingSuccessBlock)successBlock
                  failBlock:(ABNetworkingFailBlock)failBlock;

+ (NSString *)makeServerAddressWith:(NSString *)appName eventCategory:(NSString *)eventCategory;
+ (NSString *)makeAttributionServerAddress:(NSString *)appName eventCategory:(NSString *)eventCategory deviceUUID:(NSString *)deviceUUID;

+ (NSString *)makeRoutingServerAddressWith:(NSString*)uuid __deprecated_msg("");
+ (NSString *)makeCookieMatchApiAddressWith:(NSString*)uuid deviceToken:(NSString*)deviceToken appToken:(NSString*)appToken __deprecated_msg("");
+ (NSString *)makeBackupServerAddress;

+ (NSString *)getMethodTypeFromNetworkingType:(ABNetworkingType)type;

+ (void)setDebugNetworkMode:(BOOL)isDebug;

- (id)initWithSuccessBlock:(ABNetworkingSuccessBlock)successBlock
                 failBlock:(ABNetworkingFailBlock)failBlock;

- (id)initWithSuccessBlock:(ABNetworkingSuccessBlock)successBlock
                 failBlock:(ABNetworkingFailBlock)failBlock
                retryBlock:(ABNetworkingRetryBlock)retryBlock;

-(void)performPostWithUrl:(NSString *)url
               parameters:(NSDictionary *)parameters;

#pragma mark - handling fail request (binary backoff)
- (void)handleFailRequest:(NSError *)error responseJson:(id)responseJson connection:(NSURLConnection *)connection;
#pragma mark - session

+(NSDictionary*) loadSessionInfo;
+(void) setSessionTimeOut:(NSInteger)timeout;
+(NSDictionary*) makeNewSession;
+(NSDictionary*) getCurrentSession:(BOOL)isNeedRenewCheck;

+(void) updateSessionStartTime;
@end
