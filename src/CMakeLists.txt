cmake_minimum_required(VERSION 3.10)

add_executable(opengl_tut)
target_sources(opengl_tut
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(opengl_tut LINK_PRIVATE glfw glad)
target_include_directories(opengl_tut
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${GLFW_INCLUDE_DIRS}
            ${GLAD_INCLUDE_DIRS})

