import { useState } from "react";
import "./App.css";

function App() {
  const [currState, setCurrState] = useState(1);
  const [preState, setPreState] = useState(0);
  
  const handleChange = ()=>{
    setPreState(currState);
    setCurrState(currState+1);
  }
  return (
    <div className="App">
      <div className="stateName">
        <h2>Current State</h2>
        <h2>Previous State</h2>
      </div>
      <div className="state">
        <h3>{currState}</h3>
        <h3>{preState}</h3>
      </div>
      <button onClick={handleChange} >CliCk To Change</button>
    </div>
  );
}

export default App;
