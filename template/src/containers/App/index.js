// @flow
import * as React from 'react';
import ErrorBoundary from 'components/ErrorBoundary';
import AppError from 'components/AppError';
import logo from '../../images/logo.svg';
import HelloReason from '../../hello_reason';
import './style.scss';

const App = () => (
  <ErrorBoundary fallbackComponent={AppError}>
    <main>
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <h1 className="App-title">Welcome to React</h1>
      </header>
      <HelloReason message="Hello from Reason!" />
    </main>
  </ErrorBoundary>
);

export default App;
