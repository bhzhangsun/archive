import React, { useEffect, useRef } from 'react';
import { Quill } from 'react-quill';
import 'react-quill/dist/quill.snow.css';
import './index.less';

export default () => {
    const containerRef = useRef(null);
    const quill = useRef<any>(null);

    useEffect(() => {
        if (!containerRef.current || quill.current) return;
        quill.current = new Quill(containerRef.current, {
            bounds: '#root',
            theme: 'snow'
        });
    }, [])

    return <div ref={containerRef} className="quill-container"></div>
}