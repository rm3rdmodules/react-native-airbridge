
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
  public void setUserId(String userId) {

    AirBridge.getTracker().setUserId(userId);
  }

  @ReactMethod
  public void setUserEmail(String email) {

    AirBridge.getTracker().setUserEmail(email);
  }

  @ReactMethod
  public void SignUpEvent(ReadableMap params) {
    SignUpEvent event = new SignUpEvent();
    this._sendEvent(event, params);
    AirBridge.getTracker().send(event);
  }

  @ReactMethod
  public void SignInEvent(ReadableMap params) {
    SignInEvent event = new SignInEvent();
    this._sendEvent(event, params);
    AirBridge.getTracker().send(event);
  }

  @ReactMethod
  public void HomeViewEvent(ReadableMap params) {
    HomeViewEvent event = new HomeViewEvent();
    AirBridge.getTracker().send(event);
  }


  @ReactMethod
  public void GoalEvent(String category, ReadableMap params) {
    GoalEvent event = new GoalEvent(category);
    this._sendEvent(event, params);
    AirBridge.getTracker().send(event);
  }

  private void _sendEvent(Object event, ReadableMap params) {
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
}