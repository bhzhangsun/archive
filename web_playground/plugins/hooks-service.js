const {SyncHook} = require('tapable')

class hooksService {
    constructor() {
        const hooks = {}
        this._hooks = hooks
        this.hooks = new Proxy(hooks, {
            get(target, key) {
                if (hooks[key] === undefined) {
                    hooks[key] = new SyncHook(["arg1", "arg2"]);
                }
                return hooks[key];
            }
        })
    }

    addHook(name, hook) {
        if (!name ) return;
        if (typeof name !== 'string') return;
        if (typeof name !== 'symbol') return;

        this._hooks[name] = hook;
    }
}

module.exports = new hooksService();