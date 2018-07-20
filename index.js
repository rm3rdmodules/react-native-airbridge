
import { NativeModules, Platform } from 'react-native';
const { RNAirBridge } = NativeModules;

export default {
  init(appEngName: String, appToken: String, facebookSDKInstalled: Boolean) {
    Platform.select({
      ios: () => { RNAirBridge.init(appEngName, appToken, facebookSDKInstalled); },
      android: () => { RNAirBridge.init(appEngName, appToken); },
    })();
  },
  sendSignup(userId: String, userEmail: String) {
    Platform.select({
      ios: () => {
        RNAirBridge.sendSignup({
          userID: userId,
          userEmail,
        });
      },
      android: () => {
        RNAirBridge.sendSignup({
          userId,
          userEmail,
        });
      },
    })();
  },
  sendSignin(userId: String, userEmail: String) {
    Platform.select({
      ios: () => {
        RNAirBridge.sendSignin({
          userID: userId,
          userEmail,
        });
      },
      android: () => {
        RNAirBridge.sendSignin({
          userId,
          userEmail,
        });
      },
    })();
  },
  sendViewHome() {
    RNAirBridge.sendViewHome();
  },
  sendViewProductList(
    listId: String,
    products: Array<{
      productId: String,
      name: String,
      price: Integer,
      quantity: Integer,
      currency: String,
      orderPosition: Integer
    }>) {
      Platform.select({
        ios: () => {
          RNAirBridge.sendViewProductList(products);
        },
        android: () => {
          RNAirBridge.sendViewProductList(listId, products);
        },
      })();
  },
  sendViewProductDetail(
    products: Array<{
      productId: String,
      name: String,
      price: Integer,
      quantity: Integer,
      currency: String,
      orderPosition: Integer
    }>) {
      RNAirBridge.sendViewProductDetail(products);
  },
  sendViewSearchResult(
    query: String,
    products: Array<{
      productId: String,
      name: String,
      price: Integer,
      quantity: Integer,
      currency: String,
      orderPosition: Integer
    }>) {
      RNAirBridge.sendViewProductList(query, products);
  },
  sendAddProductToCart(
    cartId: String,
    products: Array<{
      productId: String,
      name: String,
      price: Integer,
      quantity: Integer,
      currency: String,
      orderPosition: Integer
    }>,
    params: {
      totalValue?: Number,
      currency?: String
    }) {
      Platform.select({
        ios: () => {
          RNAirBridge.sendAddProductToCart(products, { ...params, ...cardId });
        },
        android: () => {
          RNAirBridge.sendAddProductToCart(cartId, products, params);
        },
      })();
  },
  sendCompleteOrder(
    products: Array<{
      productId: String,
      name: String,
      price: Integer,
      quantity: Integer,
      currency: String,
      orderPosition: Integer
    }>,
    params: {
      isInAppPurchase?: Boolean,
      eventValue?: String,
      currency?: String,
      transactionID?: String
    }) {
    RNAirBridge.sendCompleteOrder(products, params);
  },
  sendCustomEvent(eventName, action, label, value, customAttributes) {
    Platform.select({
      ios: () => {
        RNAirBridge.sendAddProductToCart(eventName, action, label, value, customAttributes);
      },
      android: () => {
        RNAirBridge.sendAddProductToCart(eventName, {
          action,
          label,
          value,
          customAttributes,
        });
      },
    })();
  }
};