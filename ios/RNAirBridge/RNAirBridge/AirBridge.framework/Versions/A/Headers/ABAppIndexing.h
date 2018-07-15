//
//  ABAppIndexing.h
//  UdlSDKSample
//
//  Created by TehranSlippers on 9/21/15.
//  Copyright (c) 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreSpotlight/CoreSpotlight.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <UIKit/UIKit.h>

@interface ABAppIndexing : NSObject
+ (instancetype)instance;
+ (void) stopAirBridgeTracking;
- (void) createUserActivity:(NSDictionary*)dataDictionary ;
- (void) deleteAppindexing:(NSArray*)domainIdentifier;

@end
