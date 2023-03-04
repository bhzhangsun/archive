import React, { useEffect, useRef } from 'react';
import Quill from 'quill'
import * as Y from 'yjs'
import { WebsocketProvider } from 'y-websocket'
import { QuillBinding } from 'y-quill'
import QuillCursors from 'quill-cursors'
import 'quill/dist/quill.snow.css'
import './index.less';



export default () => {
    const containerRef = useRef(null);
    const quill = useRef<any>(null);

    useEffect(() => {
        Quill.register('modules/cursors', QuillCursors)
        const doc = new Y.Doc()
        const type = doc.getText('quill')
        const provider = new WebsocketProvider('ws://localhost:1234', 'roomname', doc)

        if (!containerRef.current || quill.current) return;
        const editor = new Quill(containerRef.current, {
            bounds: '#root',
            modules: {
                cursors: true,
                toolbar: [
                    [{ header: [1, 2, false] }],
                    ['bold', 'italic', 'underline'],
                    ['image', 'code-block']
                ]
            },
            placeholder: 'Start collaborating...',
            theme: 'snow'
        });
        quill.current = editor;
        // Optionally specify an Awareness instance, if supported by the Provider
        const binding = new QuillBinding(type, editor, provider.awareness)
    }, [])

    return <div ref={containerRef} className="quill-container"></div>
}