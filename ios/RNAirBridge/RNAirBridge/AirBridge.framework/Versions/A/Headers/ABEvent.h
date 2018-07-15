//
//  ABEvent.h
//  AirBridge
//
//  Created by donutt on 2017. 8. 8..
//  Copyright © 2017년 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABUser.h"
#import "ABEvent.h"
#import "ABCommon.h"
#import "ABNetworking.h"
#import "ABConstants.h"
#import "ABRequestOperation.h"
#import "ABRequestOperationWorker.h"
#import "ABNetworkRequestFormatter.h"

@interface ABEvent : NSObject

@property (strong) NSString *appName;
@property (strong) ABUser *user;

- (BOOL)sendEventWithRqFormatter:(ABNetworkRequestFormatter *)rqFormatter;
- (void)addRequestOperation:(NSString *)path
           requestFormatter:(ABNetworkRequestFormatter *)rqFormatter
                 methodType:(ABNetworkingType)methodType
                requestName:(NSString *)requestName;

@end
