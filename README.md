# react-native-airbridge

## Getting started

`$ npm install react-native-airbridge --save`

### Make sure 'AirBridge' is in your ios/Podfile like below

```
target 'MyTestApp' do

  pod 'AirBridge'

end
```

### Pod install
```
$ cd ios/
$ pod install
```

### Mostly automatic installation

`$ react-native link react-native-airbridge`

### Manual installation

#### iOS

1.  In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2.  Go to `node_modules` ➜ `react-native-airbridge` and add `RNAirBridge.xcodeproj`
3.  In XCode, in the project navigator, select your project. Add `libRNAirBridge.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4.  Run your project (`Cmd+R`)<

#### Android

1.  Open up `android/app/src/main/java/[...]/MainActivity.java`

- Add `import com.reactlibrary.RNAirBridgePackage;` to the imports at the top of the file
- Add `new RNAirBridgePackage()` to the list returned by the `getPackages()` method

2.  Append the following lines to `android/settings.gradle`:
    ```
    include ':react-native-airbridge'
    project(':react-native-airbridge').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-airbridge/android')
    ```
3.  Insert the following lines inside the dependencies block in `android/app/build.gradle`:
    ```
      compile project(':react-native-airbridge')
    ```

## Usage

```javascript
import AirBridge from "react-native-airbridge";

    const products = [{
      productId: 'prd-1',
      name: '상품1',
      price: 3000,
      quantity: 1,
      currency: 'KRW',
      orderPosition: 1,
    }, {
      productId: 'prd-1',
      name: '상품1',
      price: 3000,
      quantity: 1,
      currency: 'KRW',
      orderPosition: 1,
    }];
    AirBridge.init('your eng app name', 'airbridge token', false);
    AirBridge.sendSignin('2jw0718', '2jw0718@gmail.com');
    AirBridge.sendSignup('2jw0718', '2jw0718@gmail.com');
    AirBridge.sendViewHome();
    AirBridge.sendViewProductList('prd-list-id', products);
    AirBridge.sendViewProductDetail(products);
    AirBridge.sendViewSearchResult('search query', products);
    AirBridge.sendAddProductToCart('cart_id', products, { totalValue: 3000, currency: 'KRW' });
    AirBridge.sendCompleteOrder(products, {
      isInAppPurchase: false,
      transactionID: '123456789',
      eventValue: 3000,
      currency: 'KRW',
    });
```
