import React from 'react'
import ReactDOM from 'react-dom/client'
import { BrowserRouter, Routes, Route } from 'react-router-dom'
import App from './App'
import Quill from './views/quill/index'
import './index.css'

ReactDOM.createRoot(document.getElementById('root') as HTMLElement).render(
  <React.StrictMode>
    <BrowserRouter>
      <Routes>
        {/* <Route path='/' element={<App></App>}></Route> */}
        <Route path='/quill' element={<Quill></Quill>}></Route>
      </Routes>
    </BrowserRouter>
  </React.StrictMode>,
)
