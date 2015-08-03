cmake_minimum_required(VERSION 2.8.12)

project(read-write-files)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(read-write-files ${SOURCES})