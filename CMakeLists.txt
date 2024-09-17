cmake_minimum_required(VERSION 3.5)
project(NobleCore)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Uncomment the below line to enable 64-bit values.
# add_compile_definitions(SET_VALUE_64)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        NobleCoreTests
        NobleCore.h
        Translation.cpp
        Translation.h
        Op.cpp
        Op.h
        Frame.cpp
        Frame.h
        Address.cpp
        Address.h
        List.cpp
        List.h
        Value.cpp
        Value.h
        NobleCoreTests/NobleCoreTests.cpp
        NobleCoreTests/TranslationTests.cpp
        NobleCoreTests/ListTests.cpp
        NobleCoreTests/ValueTests.cpp
)
target_link_libraries(
        NobleCoreTests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(NobleCoreTests)
