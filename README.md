<h1 align="center">
  JS with Reason Scripts - a fork of [Reason Scripts](https://github.com/reasonml-community/reason-scripts)
 </h1>

<pre align="center">
  $ yarn create react-app my-app --scripts-version js-with-reason-scripts
</pre>

JS with Reason Scripts provides a JS entrypoint into a react app, with the ability to use [Reason](https://reasonml.github.io/) where you like while building your [React](https://facebook.github.io/react) app. It bootstraps an environment to automatically
compile all Reason code to JS, provide features like reloading and bundling, and seamlessly
use JS code from Reason, and Reason from JS code.

[![Build Status](https://travis-ci.org/rjsamson/js-with-reason-scripts.svg?branch=master)](https://travis-ci.org/rjsamson/js-with-reason-scripts)

## Getting Started

### Using [Yarn](https://yarnpkg.com/)

> Note that using `yarn create` requires Yarn 0.25 or later

To create a new app using Reason and React, run:

```
$ npm install -g bs-platform
$ yarn create react-app <app-name> --scripts-version js-with-reason-scripts
$ cd <app-name>
$ yarn start
```

Make sure to install bs-platform globally using `npm` instead of `yarn`.

### Using npm

```
$ npm install -g bs-platform create-react-app
$ create-react-app <app-name> --scripts-version js-with-reason-scripts
$ cd <app-name>
$ npm start
```

### Directory Layout

Creating a new app makes an `<app-name>` directory with the following layout:

```
<app-name>/
  README.md
  node_modules/
  package.json
  bsconfig.json
  .gitignore
  public/
    favicon.ico
    index.html
  src/
    index.js
    index.css
    App.js
    hello_reason.re
    hello_reason_test.re
    App.css
    logo.svg
```

## Features

### [Everything from Create React App](https://github.com/facebookincubator/create-react-app/blob/master/packages/react-scripts/template/README.md)

* Highly-optimized build configuration
* Pre-configured test runner
* Friendly developer environment
* "eject" Webpack config
* Environment variable configuration
* Automatic PWA configuration
* Low configuration builds

### Reason Entrypoint

Unlike Reason Scripts, the entry point to the app is `src/index.js`. From the start your new
app will be based on Javascript, but can seamlessly include ReasonML with existing JS
files and projects!

### Automatic Compilation of Reason/OCaml files

Any Reason/OCaml file will be automatically compiled to a JS file. For example,
a file called `math_fns.re` can be required by a JS file:

```js
import { add } from './math_fns.re'

const sum = add(1, 4)
```

### Jest Integration

Reason Scripts will automatically configure a [Jest](https://facebook.github.io/jest) environment
to test Reason code. Any code found in a file ending with `_test.re`, `_test.ml`
or `test.js` will be considered a test and run with Jest. From these files, the normal
Jest API can be used interacting with any other modules defined in your app. For example:

```reason
/* math_fns.re */

let add = (x, y) => x + y;
```

```reason
/* math_fns_test.re */

open Jest;

test("addition", () => {
  let num_1 = 10;
  let num_2 = 12;

  expect(Math_fns.add num_1 num_2) |> toBe(22);
});
```

Or if you prefer writing your tests in JavaScript, just don't forget to import the tested module:

```js
/* maths_fns.test.js */

import Math_fns from './math_fns.re'

test('addition', () => {
  const num1 = 10
  const num2 = 12

  expect(Math_fns.add(num1, num2)).toBe(22)
})

```

For more documentation on the Jest API, see [bs-jest](https://github.com/reasonml-community/bs-jest)

### Importing non-Reason files

You can require CSS files with:

```reason
[%bs.raw {|require('./App.css')|}];
```

or any other kind of file (like SVG's) with:

```reason
let logo : string = [%bs.raw {|require('./logo.svg')|}];
```

## Help, Tips, and Tricks

<p><details>
<summary><b>My app won't compile on a fresh install</b></summary>

Try running `npm install` in your project directory. This helps refresh missing dependencies sometimes.
</details></p>


<p><details>
<summary><b>My editor isn't autocompleting</b></summary>

Editor support is provided by Merlin. To generate a `.merlin` file, run the app
with `npm start` or `yarn start`.

See our full editor integration guide here: https://reasonml.github.io/docs/en/editor-plugins.html
</details></p>


<p><details>
<summary><b>I don't want js-with-reason-scripts to clear my terminal</b></summary>

Use `FORCE_COLOR=true react-scripts start | cat -` as your start command instead
</details></p>

<p><details>
<summary><b>Reason is awesome! Where can I learn more?</b></summary>

Checkout our fancy website: https://reasonml.github.io/!
</details></p>
