# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# configure import libs
set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../distribution)

# ${ANDROID_ABI} is handy for our purpose here. Probably this ${ANDROID_ABI} is
# the most valuable thing of this sample, the rest are pretty much normal cmake
add_library(lib_curl SHARED IMPORTED)
set_target_properties(lib_curl PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/curl/libs/${ANDROID_ABI}/libcurl.so)

# build application's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library(
        # Sets the name of the library.
        easemob-facade

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        easemob.cpp
)

target_include_directories(
        easemob-facade
        PRIVATE
        ${distribution_DIR}/curl/include
)


target_link_libraries(
        easemob-facade
        android
        lib_curl
        log
)