# react-native-airbridge

## Getting started

`$ npm install react-native-airbridge --save`

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
import RNAirBridge from "react-native-airbridge";

// TODO: What to do with the module?
RNAirBridge.init("appEngName", "appToken");
```
