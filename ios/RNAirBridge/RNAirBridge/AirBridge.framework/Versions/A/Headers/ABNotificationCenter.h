//
//  ABNotificationCenter.h
//  UdlSDKSample
//
//  Created by TehranSlippers on 8/6/15.
//  Copyright (c) 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABNotificationCenter : NSObject

+ (instancetype)instance;

- (void)willResignActiveNotification:(NSNotification*)notification ;
- (void)didEnterBackgroundNotification:(NSNotification*)notification ;
- (void)willEnterForegroundNotification:(NSNotification*)notification;
- (void)didBecomeActiveNotification:(NSNotification*)notification ;

@end
