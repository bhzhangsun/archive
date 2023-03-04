const path = require('path')
const { CleanWebpackPlugin } = require('clean-webpack-plugin')
const HtmlWebPackPlugin = require('html-webpack-plugin')
const HelloWebpackPlugin = require('./plugins/hello-webpack-plugin')


module.exports = {
  mode: "development",
  entry: "./src/main.tsx?",
  output: {
    path: path.resolve(__dirname, "./dist"),
    filename: "[name].[contenthash:8].js",
  },
  module: {
    rules: [
      {
        test: /\.[tj]sx?$/,
        exclude: /(node_modules)/,
        loader: 'babel-loader',
        options: {
          presets: [
            '@babel/preset-env',
            '@babel/preset-react',
            [
              '@babel/preset-typescript', 
              {
                "isTSX": true,
                "allExtensions": true
              }
            ]
          ],
          plugins: ["./loaders/babel-plugin-lookup.js"]
        }
      },
      {
        test: /\.less$/,
        use: ["style-loader", "css-loader", "less-loader"], // 指定要处理的.less文件的加载器
      },
      {
        test: /\.css$/,
        use: ["style-loader", "css-loader"], // 指定要处理的.css文件的加载器
      },
      {
        test: /\.(svg|jpg|png|gif)$/, // 针对这三种格式的文件使用file-loader处理
        type: 'asset',
        parser: {
          dataUrlCondition: {
            maxSize: 8192
          }
        }
      }
    ],
  },
  plugins: [
    new CleanWebpackPlugin(),
    new HtmlWebPackPlugin({
      template: path.join(__dirname, "public/index.html"),
      filename: "index.html",
    }),
    new HelloWebpackPlugin()
  ],
  resolve: {
    // directories where to look for modules (in order)
    extensions: ['.js', '.jsx', '.ts', '.tsx', ".json"],
    alias: {
      "@assets": path.resolve(__dirname, "assets"),
    },
  },
  devtool: "source-map",
  devServer: {
    static: path.join(__dirname, 'public'), // boolean | string | array | object, static file location
    compress: true, // enable gzip compression
    hot: false, // hot module replacement. Depends on HotModuleReplacementPlugin
    https: false, 
    historyApiFallback: true
  }
};