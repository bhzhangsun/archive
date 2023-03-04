cmake_minimum_required(VERSION 2.8)

include_directories(
  include
)

set(SOURCE_FILE
  json.cpp
  tokenizer.cpp
)

message("build libjson is begin...")
add_library(libjson STATIC ${SOURCE_FILE})
add_executable(json_example test/json_example.cpp ${SOURCE_FILE})

message("congratulations! build is complate.")


