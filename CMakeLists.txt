cmake_minimum_required(VERSION 3.30)

project(study)

include(FetchContent)

FetchContent_Declare(
    hegel
    GIT_REPOSITORY https://github.com/hegeldev/hegel-cpp.git
    GIT_TAG main
)

FetchContent_MakeAvailable(hegel)

set(CMAKE_CXX_STANDARD 23)

add_executable(study main.cxx)

target_link_libraries(study PRIVATE hegel)

