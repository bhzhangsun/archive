module.exports = function() {
    return {
      visitor: {
        Identifier(path) {
          const name = path.node.name;
          // reverse the name: JavaScript -> tpircSavaJ
          
          if (name === 'createElement') {
            const parent = path.getFunctionParent();

            // console.log('identifier:', path.node)
          }
        },
        CallExpression(path) {
          const {callee = {}, arguments = []} = path.node
          if (callee.property && callee.property.name === 'createElement' && arguments.length >= 2) {
            const [type, props] = arguments.slice(0, 2)
            if (type && props && type.value === 'img' && props.properties) {
              const property = props.properties.find((property) => property.type === 'ObjectProperty' && property.key.name === 'src')
              console.log('props.properties src:',  property.value.value)
            }
          }
        }
      },
    };
  }