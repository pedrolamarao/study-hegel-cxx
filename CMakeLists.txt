cmake_minimum_required(VERSION 3.30)

project(study)

include(FetchContent)

FetchContent_Declare(
    hegel
    GIT_REPOSITORY https://github.com/hegeldev/hegel-cpp.git
    GIT_TAG main
)

FetchContent_MakeAvailable(hegel)

add_subdirectory(study)
