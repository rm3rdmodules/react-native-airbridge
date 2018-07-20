//
//  ABRequestOperationWorker.h
//  UdlSDKSample
//
//  Created by TehranSlippers on 8/6/15.
//  Copyright (c) 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABRequestOperation.h"
@interface ABRequestOperationWorker : NSObject

@property (nonatomic) BOOL isStoping;
@property (nonatomic) BOOL isStopped;

+ (void) stopAirBridgeTracking ;
- (void)resetNetworkOperations ;

+(instancetype)instance;

-(void)addOperation:(ABRequestOperation*)operation;
-(void)addHighOperation:(ABRequestOperation*)operation ;
-(void)finishOperation:(ABRequestOperation*)operation;
-(void)failOperation:(ABRequestOperation*)operation;

- (void)start;
- (void)stop;

- (NSUInteger)operationCount;

@end
