let component = ReasonReact.statelessComponent("Welcome");

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div>
      <p className="App-intro"> (ReasonReact.stringToElement(message)) </p>
      <p className="App-intro">
        (ReasonReact.stringToElement("To get started, edit"))
        <code> (ReasonReact.stringToElement(" src/hello_reason.re ")) </code>
        (ReasonReact.stringToElement("and save to reload."))
      </p>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~message=jsProps##message, [||])
  );
