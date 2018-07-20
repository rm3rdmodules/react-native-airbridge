
#import "RNAirBridge.h"
#import <React/RCTConvert.h>
#import <React/RCTBridge.h>
#import <AirBridge/AirBridge.h>
#import <AirBridge/ABUserEvent.h>
#import <AirBridge/ABEcommerceEvent.h>

@implementation RNAirBridge

- (ABEcommerceEvent *) getEcommerceEvent:(NSArray *)products {
    NSMutableArray *list = [NSMutableArray new];
    for (int i = 0; i < [products count]; i++) {
        NSDictionary *row = [products objectAtIndex: i];
        NSString *idx = [RCTConvert NSString:row[@"idx"]];
        NSString *name = [RCTConvert NSString:row[@"name"]];
        NSNumber *price = [RCTConvert NSNumber:row[@"price"]];
        NSString *currency = [RCTConvert NSString:row[@"currency"]];
        NSNumber *orderPosition = [RCTConvert NSNumber:row[@"orderPosition"]];
        NSLog(@"idx %@ name %@ price %@ currency %@ orderPosition %@", idx, name, price, currency, orderPosition );

        ABProduct *product = [[ABProduct alloc] init];
        product.idx = idx;
        product.name = name;
        product.price = price;
        product.currency = currency;
        product.orderPosition = orderPosition;
        [list addObject:product];
    }
    ABEcommerceEvent *ecommerceEvent = [[ABEcommerceEvent alloc] initWithProducts:list];
    return ecommerceEvent;
}

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(init:(NSString *)appName appToken:(NSString *)appToken)
{
    [AirBridge getInstance:appToken appName:appName withLaunchOptions:self.bridge.launchOptions facebookSDKInstalled:NO];
}

RCT_EXPORT_METHOD(setUser:(NSString *)userId)
{
    [[AirBridge instance] setUser:userId];
}

RCT_EXPORT_METHOD(setEmail:(NSString *)email)
{
    [[AirBridge instance] setEmail:email];
}

RCT_EXPORT_METHOD(sendSignin:(NSDictionary *_Nullable)params)
{
    ABUser *user = [[ABUser alloc] init];
    for (NSString* key in params) {
        [user setValue:params[key] forKey:key];
    }
    ABUserEvent *userEvent = [[ABUserEvent alloc] initWithUser:user];
    [userEvent sendSignin];
}

RCT_EXPORT_METHOD(sendSignup:(NSDictionary *_Nullable)params)
{
    ABUser *user = [[ABUser alloc] init];
    for (NSString* key in params) {
        [user setValue:params[key] forKey:key];
    }
    ABUserEvent *userEvent = [[ABUserEvent alloc] initWithUser:user];
    [userEvent sendSignup];
}

RCT_EXPORT_METHOD(sendViewHome:(NSDictionary *_Nullable)params)
{
    ABEcommerceEvent *ecommerceEvent = [[ABEcommerceEvent alloc] init];
    [ecommerceEvent sendViewHome];
}

RCT_EXPORT_METHOD(sendViewProductList:(NSArray *)products)
{
    ABEcommerceEvent *ecommerceEvent = [self getEcommerceEvent:products];
    [ecommerceEvent sendViewProductList];
}

RCT_EXPORT_METHOD(sendViewSearchResult:(NSArray *)products query:(NSString *)query)
{
    ABEcommerceEvent *ecommerceEvent = [self getEcommerceEvent:products];
    ecommerceEvent.query = query;
    [ecommerceEvent sendViewSearchResult];
}

RCT_EXPORT_METHOD(sendViewProductDetail:(NSArray *)products)
{
    ABEcommerceEvent *ecommerceEvent = [self getEcommerceEvent:products];
    [ecommerceEvent sendViewProductDetail];
}

RCT_EXPORT_METHOD(sendAddProductToCart:(NSArray *)products)
{
    ABEcommerceEvent *ecommerceEvent = [self getEcommerceEvent:products];
    [ecommerceEvent sendAddProductToCart];
}

RCT_EXPORT_METHOD(sendCompleteOrder:(NSArray *)products)
{
    ABEcommerceEvent *ecommerceEvent = [self getEcommerceEvent:products];
    ecommerceEvent.isInAppPurchase = NO;
    ecommerceEvent.transactionID = @"123456789";
    ecommerceEvent.eventValue = [NSNumber numberWithInt:100];
    [ecommerceEvent sendCompleteOrder];
}

@end
