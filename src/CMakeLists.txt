cmake_minimum_required(VERSION 3.10)

add_executable(exe)
target_sources(exe
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Core/Window.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Core/Application.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Windows/WindowGLFW.cpp)

target_link_libraries(exe LINK_PRIVATE glfw glad)
target_include_directories(exe
        PUBLIC
            ${TUTORIAL_SOURCE_DIR}/include
            ${GLFW_INCLUDE_DIRS}
            ${GLAD_INCLUDE_DIRS})

# GLFW option
option(USE_GLFW "Use GLFW windowing" ON)
if(USE_GLFW)
    target_compile_definitions(exe PUBLIC USE_GLFW)
endif(USE_GLFW)
