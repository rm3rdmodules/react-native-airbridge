
import { NativeModules, Platform } from 'react-native';

const { RNAirBridge } = NativeModules;

export default {
  init(appEngName: string, appToken: string, facebookSDKInstalled: Boolean) {
    Platform.select({
      ios: () => { RNAirBridge.init(appEngName, appToken, facebookSDKInstalled); },
      android: () => { RNAirBridge.init(appEngName, appToken); },
    })();
  },
  sendSignup(userId: string, userEmail: string) {
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
  sendSignin(userId: string, userEmail: string) {
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
    listId: string,
    products: Array<{
      productId: string,
      name: string,
      price: number,
      quantity: number,
      currency: string,
      orderPosition: number
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
      productId: string,
      name: string,
      price: number,
      quantity: number,
      currency: string,
      orderPosition: number
    }>) {
      RNAirBridge.sendViewProductDetail(products);
  },
  sendViewSearchResult(
    query: string,
    products: Array<{
      productId: string,
      name: string,
      price: number,
      quantity: number,
      currency: string,
      orderPosition: number
    }>) {
      RNAirBridge.sendViewSearchResult(query, products);
  },
  sendAddProductToCart(
    cartId: string,
    products: Array<{
      productId: string,
      name: string,
      price: number,
      quantity: number,
      currency: string,
      orderPosition: number
    }>,
    params: {
      totalValue?: number,
      currency?: string
    }) {
      Platform.select({
        ios: () => {
          delete params.currency;
          delete params.totalValue;
          RNAirBridge.sendAddProductToCart(products, params);
        },
        android: () => {
          RNAirBridge.sendAddProductToCart(cartId, products, params);
        },
      })();
  },
  sendCompleteOrder(
    products: Array<{
      productId: string,
      name: string,
      price: number,
      quantity: number,
      currency: string,
      orderPosition: number
    }>,
    params: {
      isInAppPurchase?: Boolean,
      eventValue?: string,
      transactionID?: string,
      currency?: string
    }) {
      Platform.select({
        ios: () => {
          delete params.currency;
          RNAirBridge.sendCompleteOrder(products, params);
        },
        android: () => {
          RNAirBridge.sendCompleteOrder(products, params);
        },
      })();
  },
  sendCustomEvent(eventName: string, action: string, label: string, value: number, customAttributes: object) {
    Platform.select({
      ios: () => {
        RNAirBridge.sendCustumEvent(eventName, action, label, value, customAttributes);
      },
      android: () => {
        RNAirBridge.sendCustumEvent(eventName, {
          action,
          label,
          value,
          customAttributes,
        });
      },
    })();
  }
};