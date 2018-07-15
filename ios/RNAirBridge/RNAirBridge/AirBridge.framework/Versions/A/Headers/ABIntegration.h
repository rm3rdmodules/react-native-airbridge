//
//  ABIntegration.h
//  AirBridge
//
//  Created by Donutt on 2016. 11. 22..
//  Copyright © 2016년 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCommon.h"

@interface ABIntegration : NSObject

+ (instancetype)instance;

- (NSDictionary *)getIntegrationPoints;

- (void)fetchIntegrations;

- (void)turnOnIntegration:(NSString*)source;
- (void)turnOnIntegrations:(NSArray*)sources;

@end
