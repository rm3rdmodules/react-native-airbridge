//
//  ABEcommerceEvent.h
//  AirBridge
//
//  Created by donutt on 2017. 8. 8..
//  Copyright © 2017년 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABEvent.h"
#import "ABProduct.h"

@interface ABEcommerceEvent : ABEvent

@property (nonatomic, strong) NSArray *products;

@property (strong) NSString *productListID;
@property (strong) NSString *query;
@property (strong) NSString *cartID;
@property (strong) NSString *transactionID;
@property (strong) NSNumber *eventValue;
@property (strong) NSDictionary *eventCustomAttributes;
@property BOOL isInAppPurchase;

- (id)initWithProducts:(NSArray<ABProduct *> *)products;

- (BOOL)sendViewHome;
- (BOOL)sendViewProductList;
- (BOOL)sendViewSearchResult;
- (BOOL)sendViewProductDetail;
- (BOOL)sendAddProductToCart;
- (BOOL)sendCompleteOrder;

@end
