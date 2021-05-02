cmake_minimum_required(VERSION 3.7)

project(lexus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(LEXUS_SHARED_SOURCES
    src/command.cpp
)

set(LEXUS_SOURCES
    src/main.cpp
    ${LEXUS_SHARED_SOURCES}
)

include_directories(
    include
    /usr/local/include
)

find_library(IO_BUFFER libio-buffer.a)
message(STATUS "Found io-buffer library: ${IO_BUFFER}")

find_library(YAML_PARSER libyaml-parser.a)
message(STATUS "Found yaml-parser library: ${YAML_PARSER}")

add_executable(
    ${PROJECT_NAME} src/main.cpp
    ${LEXUS_SOURCES}
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME}
    ${IO_BUFFER}
    ${YAML_PARSER}
)
