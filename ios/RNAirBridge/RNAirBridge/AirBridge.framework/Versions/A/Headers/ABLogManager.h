//
//  ABLogManager.h
//  AirBridge
//
//  Created by Donutt on 2015. 10. 22..
//  Copyright © 2015년 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABConstants.h"

#define ABDebugLogEx(type, ex, x, ...) __ABDebugLogEx(type, ex, x, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

@interface ABLogManager : NSObject


void __ABDebugLogEx(ABLogType type, NSException *ex, NSString* format,const char* _func,int line, ...);
void ABDebugLog(ABLogType type, NSString* format,const char* _func,int line, ...);

void setCurrentLogLevel(ABLogType logType);

@end
