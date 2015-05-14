cmake_minimum_required(VERSION 2.8)

add_executable(curl_example curl_example.cpp)

set (CURL_USE_STATIC_LIBS ON)
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
target_link_libraries(curl_example ${CURL_LIBRARIES})

