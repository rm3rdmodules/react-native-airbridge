#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif
#import <AirBridge/ABEcommerceEvent.h>

@interface RNAirBridge : NSObject <RCTBridgeModule>

- (ABEcommerceEvent *) getEcommerceEvent:(NSArray *)products;

@end
