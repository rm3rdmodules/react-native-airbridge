//
//  ABProduct.h
//  AirBridge
//
//  Created by donutt on 2017. 8. 8..
//  Copyright © 2017년 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABProduct : NSObject

- (NSDictionary *)toDictionary;

@property (nonatomic, strong) NSString *idx;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSNumber *price;
@property (nonatomic, strong) NSString *currency;
@property (nonatomic, strong) NSNumber *orderPosition;
@property (nonatomic, strong) NSNumber *quantity;

@end
