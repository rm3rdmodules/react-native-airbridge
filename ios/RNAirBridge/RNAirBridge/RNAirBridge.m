
#import "RNAirBridge.h"
#import <React/RCTBridge.h>
#import <AirBridge/AirBridge.h>
#import <AirBridge/ABUserEvent.h>

@implementation RNAirBridge

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(init:(NSString *)appName appToken:(NSString *)appToken)
{
    [AirBridge getInstance:appToken appName:appName withLaunchOptions:self.bridge.launchOptions facebookSDKInstalled:NO];
}

RCT_EXPORT_METHOD(setUserId:(NSString *)userId)
{
    [[AirBridge instance] setUser:userId];
}

RCT_EXPORT_METHOD(setUserEmail:(NSString *)email)
{
    [[AirBridge instance] setEmail:email];
}

RCT_EXPORT_METHOD(SignUpEvent:(NSDictionary *_Nullable) params)
{
    ABUser *user = [[ABUser alloc] init];
    for (NSString* key in params) {
        [user setValue:params[key] forKey:key];
    }
    ABUserEvent *userEvent = [[ABUserEvent alloc] initWithUser:user];
    [userEvent sendSignup];
}

@end
