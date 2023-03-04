const hooksService = require('./hooks-service')

class HelloWebpackPlugin {
    constructor() {
        this.name = 'helloWebpackPlugin'
    }

    apply(compiler) {
        compiler.hooks.beforeCompile.tap(this.name, (compilation) => {
            
            console.log('hello, webpack will compile!')
        })

        hooksService.hooks.hello.tap(this.name, (n, s) => {
            console.log('hello, hello hook!', n, s)
        })

        compiler.hooks.run.tapAsync(this.name, (compiler, callback) => {
            hooksService.hooks.hello.call(1, 'hello');
            setTimeout(() => {
                console.log('async wait 1s')
                callback()
            }, 1000);
        })

        compiler.hooks.done.tap(this.name, (compilation) => {
            console.log('hello, webpack is done!')
        })
    }
}

module.exports = HelloWebpackPlugin