
package com.reactlibrary;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.ReadableMapKeySetIterator;
import com.facebook.react.bridge.ReadableType;
import io.airbridge.AirBridge;
import io.airbridge.statistics.events.inapp.SignUpEvent;
import io.airbridge.statistics.events.inapp.SignInEvent;
import io.airbridge.statistics.events.GoalEvent;
import io.airbridge.ecommerce.HomeViewEvent;
import java.lang.reflect.Method;
import android.util.Log;

public class RNAirBridgeModule extends ReactContextBaseJavaModule {

  private final ReactApplicationContext reactContext;

  public RNAirBridgeModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.reactContext = reactContext;
  }

  @Override
  public String getName() {

    return "RNAirBridge";
  }

  @ReactMethod
  public void init(String appName, String appToken) {

    AirBridge.init(this.reactContext, appName, appToken);
  }

  @ReactMethod
  public void setCookieMatchingPeriod(int period) {

    // AirBridge.setCookieMatchingPeriod(period);
  }

  @ReactMethod
  public void setUser(String userId) {

    AirBridge.getTracker().setUserId(userId);
  }

  @ReactMethod
  public void setEmail(String email) {

    AirBridge.getTracker().setUserEmail(email);
  }

  @ReactMethod
  public void sendSignup(ReadableMap params) {
    SignUpEvent event = new SignUpEvent();
    this.setEventMethod(event, params);
    AirBridge.getTracker().send(event);
  }

  @ReactMethod
  public void sendSignin(ReadableMap params) {
    SignInEvent event = new SignInEvent();
    this.setEventMethod(event, params);
    AirBridge.getTracker().send(event);
  }

  @ReactMethod
  public void sendSignout(ReadableMap params) {
    SignOutEvent event = new SignOutEvent()
    AirBridge.getTracker().sendEvent(event);
  }

  @ReactMethod
  public void sendViewHome(ReadableMap params) {
    HomeViewEvent event = new HomeViewEvent();
    AirBridge.getTracker().send(event);
  }

  @ReactMethod
  public void sendViewProductList(String listId, ReadableArray products) {
    ProductListViewEvent event = new ProductListViewEvent(listId, this.getProducts(products));
    AirBridge.getTracker().sendEvent(event);
  }

  @ReactMethod
  public void sendViewProductDetail(ReadableArray product) {
    ProductDetailsViewEvent event = new ProductDetailsViewEvent(this.getProducts(product));
    AirBridge.getTracker().sendEvent(event);
  }

  @ReactMethod
  public void sendViewSearchResult(String query, ReadableArray products) {
    SearchResultViewEvent event = new SearchResultViewEvent(query, this.getProducts(products));
    AirBridge.getTracker().sendEvent(event);
  }

  @ReactMethod
  public void sendAddProductToCart(String cartId, ReadableArray products, ReadableMap params) {
    AddedToCartEvent event = new AddedToCartEvent(cartId, this.getProducts(products));
    this.setEventMethod(event, params);
    AirBridge.getTracker().sendEvent(event);
  }

  @ReactMethod
  public void sendCompleteOrder(ReadableArray products, ReadableMap params) {
    PurchaseEvent event = new PurchaseEvent(this.getProducts(products));
    this.setEventMethod(event, params);
    AirBridge.getTracker().sendEvent(event);
  }

  @ReactMethod
  public void setCustomEvent(String category, ReadableMap params) {
    GoalEvent event = new GoalEvent(category);
    this.setEventMethod(event, params);
    AirBridge.getTracker().send(event);
  }

  private void setEventMethod(Object event, ReadableMap params) {
    try {

      ReadableMapKeySetIterator iterator = params.keySetIterator();
      Method method;
      while (iterator.hasNextKey()) {
        String key = iterator.nextKey();
        ReadableType type = params.getType(key);
        String methodName = "set" + Character.toUpperCase(key.charAt(0)) + key.substring(1);

        switch (type) {
          case Null:

            break;
          case Boolean:

            break;
          case Number:
            // Can be int or double.
            method = event.getClass().getMethod(methodName, int.class);
            method.invoke(event, params.getDouble(key));
            break;
          case String:
            method = event.getClass().getMethod(methodName, String.class);
            method.invoke(event, params.getString(key));
            break;
          case Map:

            break;
          case Array:

            break;
          default:
            throw new IllegalArgumentException("Could not convert object with key: " + key + ".");
        }
      }
    }
    catch(Exception e) {
      Log.e("RNAirBidgeModule", "Exception: " + Log.getStackTraceString(e));
    }
  }

  private List<Product> getProducts(ReadableArray products) {
    List<Product> list;
    for (int i = 0; i < products.size(); i++) {
      ReadableMap row = products.get(i);
      list.add(this.getProduct(row));
    }

    return list;
  }

  private Product getProduct(ReadableMap product) {
    Product data = new Product();
    data.setProductId(product.getString('productId'));
    data.setName(product.getString('name'));
    data.setCurrency(product.getString('currency'));
    data.setPrice(product.getDouble('price'));
    data.setQuantity(product.getDouble('quantity'));
    data.setPositionInList(product.getDouble('orderPosition'));
    return data;
  }
}