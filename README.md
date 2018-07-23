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

### Automatic installation

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
## Supported Events

* [x] [Signup](https://docs.airbridge.io/ko/developer_guide/1-1-2.html#signup)
* [x] [Signin](https://docs.airbridge.io/ko/developer_guide/1-1-2.html#signin)
* [x] [Home Screen View](https://docs.airbridge.io/ko/developer_guide/1-1-2.html#homeview)
* [x] [Product List](https://docs.airbridge.io/ko/developer_guide/1-1-2.html#productlistview)
* [x] [Search Result View](https://docs.airbridge.io/ko/developer_guide/1-1-2.html#searchresultview)
* [x] [Product View](https://docs.airbridge.io/ko/developer_guide/1-1-2.html#productdetailsview)
* [x] [Add To Cart](https://docs.airbridge.io/ko/developer_guide/1-1-2.html#addedtocart)
* [x] [Purchasing](https://docs.airbridge.io/ko/developer_guide/1-1-2.html#purchase)
* [x] [Signout](https://docs.airbridge.io/ko/developer_guide/1-1-2.html#signout)

## Usage

```javascript
import AirBridge from "react-native-airbridge";

// Your products
const products = [{
  productId: 'prd-1',
  name: 'product-name1',
  price: 3000,
  quantity: 1,
  currency: 'KRW',
  orderPosition: 1,
}, {
  productId: 'prd-2',
  name: 'product-name2',
  price: 2000,
  quantity: 3,
  currency: 'KRW',
  orderPosition: 2,
}];

// Initialize
AirBridge.init('your eng app name', 'airbridge token', false);

// Signin
AirBridge.sendSignin('userId', 'userEmail');

// Signup
AirBruserIe.sendSignup('userId', 'userEmail');

// Home Screen View
AirBridge.sendViewHome();

// Product List
AirBridge.sendViewProductList('prd-list-id', products);

// Product View
AirBridge.sendViewProductDetail(products);

// Search Result View
AirBridge.sendViewSearchResult('search query', products);

// Search Result View
AirBridge.sendAddProductToCart('cart_id', products, { totalValue: 3000, currency: 'KRW' });

// Purchasing
AirBridge.sendCompleteOrder(products, {
  isInAppPurchase: false,
  transactionID: '123456789',
  eventValue: 3000,
  currency: 'KRW',
});

// Custom Event
AirBridge.sendCustomEvent('category', {
  action: 'action',
  label: 'label',
  value: 3412,
  customAttribute: products[0]
});
```
