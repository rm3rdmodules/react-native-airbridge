//
//  ABNetworkRequestFormatter.h
//  AirBridge
//
//  Created by Donutt on 2017. 2. 23..
//  Copyright © 2017년 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABPage.h"

@interface ABNetworkRequestFormatter : NSObject

+ (ABNetworkRequestFormatter *)getRequestDataFormatter;
+ (NSString*)getDeviceUUID;

- (void)addEventDataToFormat:(NSNumber *)exActiveStatus sessionInfo:(NSDictionary*) sessionInfo;
- (void)addEventDataToFormat:(NSNumber *)exActiveStatus deeplink:(NSString *)deeplinkString sessionInfo:(NSDictionary*) sessionInfo;
- (void)addEventDataToFormat:(NSNumber *)exActiveStatus goal:(NSDictionary *)goalDictionary sessionInfo:(NSDictionary*) sessionInfo;
- (void)addEventDataToFormat:(NSNumber *)exActiveStatus page:(ABPage *)page sessionInfo:(NSDictionary*)sessionInfo;
- (void)setRequestTimestampToNow ;

- (void)setExternalUserID:(NSString *)externalUserID ;
- (void)setExternalUserEmail:(NSString *)externalUserEmail ;

- (NSMutableDictionary *)toDictionary;


@property (nonatomic, strong) NSNumber *requestTimestamp;

@end
