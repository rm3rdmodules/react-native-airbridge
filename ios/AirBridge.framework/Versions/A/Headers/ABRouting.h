//
//  ABRouting.h
//  UdlSDKSample
//
//  Created by TehranSlippers on 8/12/15.
//  Copyright (c) 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^abDefaultRoutingCallback) (NSString *routing, NSDictionary *params,NSError *error);
typedef void (^abSimpleLinkRoutingCallback) (NSString *routing, NSDictionary *params,NSError *error);
typedef void (^abAutoRoutingCallback) (NSDictionary *params);

@interface ABRouting : NSObject

+ (instancetype)instance;

- (void)setDefaultRoutingCallback:(abDefaultRoutingCallback)defaultRouting;
- (void)setSimpleLinkeRoutingCallback:(abSimpleLinkRoutingCallback)slRouting;


- (void)route:(NSString*)routingString processBlock:(abAutoRoutingCallback)callback;
- (void)route:(NSString*)routeString description:(NSString*)desc processBlock:(abAutoRoutingCallback)callback;

- (void)fireRoute:(NSURL*)url ;
- (void)fireRouteWithSimpleLink:(NSURL*)url ;
- (int)fireRoute:(NSString*)path queryDictionary:(NSDictionary*)queryDictionary ;

- (void)notifyNewAttributionToABAttribution:(NSURL*)url ;

- (void)setInstallRoutingTimerNow;

- (BOOL)checkRouteString:(NSString*)routeString ;
- (NSDictionary*)getRoutingParametersWithPath:(NSArray*)pathComponents routeComponents:(NSArray*)routeComponents;
- (NSDictionary *)getDictionaryWith:(NSString *)queryString;

@end
