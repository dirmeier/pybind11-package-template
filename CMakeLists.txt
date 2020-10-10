cmake_minimum_required(VERSION 3.16)

project(lsbn LANGUAGES CXX)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fprofile-generate -fsanitize=address,undefined")

include(GNUInstallDirs)
include(FeatureSummary)
include(GoogleTest)
find_package(GTest REQUIRED)

include_directories(example/include)

foreach(el
    -Wdouble-promotion
    -Wduplicated-cond
    -Wduplicated-branches
    -Wlogical-op
    -Wnull-dereference
    -Wrestrict
    -Wuseless-cast
    -Wshadow
    -Wformat=1)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${el}")
endforeach()


add_library(
    example_lib STATIC
        example/src/clazz.cpp
)

add_executable(
    example
        example/src/main.cpp
)

target_link_libraries(
    example PRIVATE
        example_lib
)

add_executable(
    test_example
        tests/test.cpp
)

target_include_directories(
    test_example PRIVATE
        pthread
)

target_link_libraries(
    test_example PRIVATE
        example_lib
        ${GTEST_BOTH_LIBRARIES}
        pthread
)

enable_testing()
add_test(NAME main_test COMMAND test_example)

feature_summary(WHAT ALL)
MESSAGE(STATUS "Using CMAKE_CXX_COMPILER: " ${CMAKE_CXX_COMPILER})
MESSAGE(STATUS "Using CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})
if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    MESSAGE(STATUS "Using CMAKE_CXX_FLAGS_DEBUG: " ${CMAKE_CXX_FLAGS_DEBUG})
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    MESSAGE(STATUS "Using CMAKE_CXX_FLAGS_RELEASE: " ${CMAKE_CXX_FLAGS_RELEASE})
endif()
