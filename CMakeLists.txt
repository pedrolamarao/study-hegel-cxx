cmake_minimum_required(VERSION 3.30)

project(study)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
    hegel
    GIT_REPOSITORY https://github.com/hegeldev/hegel-cpp.git
    GIT_TAG v0.3.5
)

FetchContent_MakeAvailable(hegel)

add_executable(study main.cxx)

target_link_libraries(study PRIVATE hegel)

add_test(NAME study COMMAND study)
