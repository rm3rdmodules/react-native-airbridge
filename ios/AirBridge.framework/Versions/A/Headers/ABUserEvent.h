//
//  ABUserEvent.h
//  AirBridge
//
//  Created by donutt on 2017. 8. 9..
//  Copyright © 2017년 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABEvent.h"

@interface ABUserEvent : ABEvent

@property (strong) NSString *eventAction;
@property (strong) NSString *eventLabel;
@property (strong) NSNumber *eventValue;
@property (strong) NSDictionary *eventCustomAttributes;

- (id)initWithUser:(ABUser *)user;

- (BOOL)sendSignup;
- (BOOL)sendSignin;
- (BOOL)expireUser;//logOut

@end
