import React from 'react'

class Student {
    name: string
    age: Number
    constructor(name: string, age: Number) {
        this.name = name
        this.age = age
    }

    greet() {
        console.log(`Hello, my name is ${this.name}`)
    }
}

const testPromise = (): Promise<string> => {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve('1')
        }, 1000)
    })
}

const studentA = new Student('a', 20)
studentA.greet()
testPromise().then(data => {
    console.log('data', data)
})


const A = <img src="http://hello.com">hello</img>;
