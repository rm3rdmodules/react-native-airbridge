//
//  ABAttribution.h
//  AirBridge
//
//  Created by Donutt on 2016. 11. 22..
//  Copyright © 2016년 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABAttribution : NSObject
+ (void) stopAirBridgeTracking;

+ (instancetype)instance;

- (void)fillAttributionWithUrl:(NSURL*)url andParameters:(NSDictionary*)parameters;
- (void)attributionIsChanged;

@property (nonatomic,strong) NSString *source;
@property (nonatomic,strong) NSString *campaign;
@property (nonatomic,strong) NSString *adgroup;
@property (nonatomic,strong) NSString *adcreative;

@property (nonatomic,strong) NSString *medium;
@property (nonatomic,strong) NSString *searchKeyword;
@property (nonatomic,strong) NSString *adcontent;

@property (nonatomic,strong) NSString *shortId;

@end
