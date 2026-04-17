set(CMAKE_CXX_STANDARD 23)

add_executable(study main.cxx)

target_link_libraries(study PRIVATE hegel)
