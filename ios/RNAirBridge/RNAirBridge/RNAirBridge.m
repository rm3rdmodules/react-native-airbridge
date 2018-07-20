
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
        NSString *idx = [RCTConvert NSString:row[@"productId"]];
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

- (void) setUserProperties:(ABUser *)user params:(NSDictionary *)params
{
    for (id key in params) {
        [user setValue:params[key] forKey:key];
        NSLog(@"setUserProperties key %@ value %@ type %d", key, params[key], [params[key] isKindOfClass:[NSString class]]);
    }
}

- (void) setEventProperties:(ABEcommerceEvent *)ecommerceEvent params:(NSDictionary *)params
{
    for (id key in params) {
        [ecommerceEvent setValue:params[key] forKey:key];
        NSLog(@"setEventProperties key %@ value %@ type %d", key, params[key], [params[key] isKindOfClass:[NSString class]]);
    }
}

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(init:(NSString *)appName appToken:(NSString *)appToken facebookSDKInstalled:(BOOL *)facebookSDKInstalled)
{
    [AirBridge getInstance:appToken appName:appName facebookSDKInstalled:facebookSDKInstalled];
}

RCT_EXPORT_METHOD(setUser:(NSString *)userId)
{
    [[AirBridge instance] setUser:userId];
}

RCT_EXPORT_METHOD(setEmail:(NSString *)email)
{
    [[AirBridge instance] setEmail:email];
}

RCT_EXPORT_METHOD(sendSignin:(NSDictionary *)params)
{
    ABUser *user = [[ABUser alloc] init];
    [self setUserProperties:user params:params];
    ABUserEvent *userEvent = [[ABUserEvent alloc] initWithUser:user];
    [userEvent sendSignin];
}

RCT_EXPORT_METHOD(sendSignup:(NSDictionary *)params)
{
    ABUser *user = [[ABUser alloc] init];
    [self setUserProperties:user params:params];
    ABUserEvent *userEvent = [[ABUserEvent alloc] initWithUser:user];
    [userEvent sendSignup];
}

RCT_EXPORT_METHOD(sendSignout)
{
    ABUserEvent *userEvent = [[ABUserEvent alloc] init];
    [userEvent expireUser];
}

RCT_EXPORT_METHOD(sendViewHome)
{
    ABEcommerceEvent *ecommerceEvent = [[ABEcommerceEvent alloc] init];
    [ecommerceEvent sendViewHome];
}

RCT_EXPORT_METHOD(sendViewProductList:(NSArray *)products)
{
    ABEcommerceEvent *ecommerceEvent = [self getEcommerceEvent:products];
    [ecommerceEvent sendViewProductList];
}

RCT_EXPORT_METHOD(sendViewProductDetail:(NSArray *)products)
{
    ABEcommerceEvent *ecommerceEvent = [self getEcommerceEvent:products];
    [ecommerceEvent sendViewProductDetail];
}

RCT_EXPORT_METHOD(sendViewSearchResult:(NSString *)query products:(NSArray *)products)
{
    ABEcommerceEvent *ecommerceEvent = [self getEcommerceEvent:products];
    ecommerceEvent.query = query;
    [ecommerceEvent sendViewSearchResult];
}

RCT_EXPORT_METHOD(sendAddProductToCart:(NSArray *)products params:(NSDictionary *)params)
{
    ABEcommerceEvent *ecommerceEvent = [self getEcommerceEvent:products];
    [self setEventProperties:ecommerceEvent params:params];
    [ecommerceEvent sendAddProductToCart];
}

RCT_EXPORT_METHOD(sendCompleteOrder:(NSArray *)products params:(NSDictionary *)params)
{
    ABEcommerceEvent *ecommerceEvent = [self getEcommerceEvent:products];
    [self setEventProperties:ecommerceEvent params:params];
    [ecommerceEvent sendCompleteOrder];
}

RCT_EXPORT_METHOD(setCustomEvent:(NSString *)eventName action:(NSString *)action label:(NSString *)label value:(NSNumber *)value customAttributes:(NSDictionary *_Nullable)customAttributes)
{
    [[AirBridge instance]
     goalWithCategory:eventName
     action:action
     label:label
     value:value
     customAttributes:customAttributes];
}
@end
