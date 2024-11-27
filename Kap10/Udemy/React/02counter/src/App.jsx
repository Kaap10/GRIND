import { useState } from 'react'

import './App.css'

function App() {

  const [counter, setCounter] = useState(0)

  // let counter = 15
  const addValue = () => {
    setCounter
  }

  return (
    <>
      <h1>React course with Kap10</h1>
      <h2>Counter Value: </h2>
      <button 
      onClick={addValue}>
        Add Value
      </button>
      <button>Add Value</button> {" "}
      <button>Remove Value</button>
      <p>footer:</p>
    </>
  )
}

export default App
