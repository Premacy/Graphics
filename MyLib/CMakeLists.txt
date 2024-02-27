cmake_minimum_required(VERSION 2.6)

project(visualization)

set(CURR_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

set(SOURCES Application.cpp Window.cpp "${CURR_DIR}/Shaders/Shaders.cpp" "${CURR_DIR}/Log/Logger.cpp" "${CURR_DIR}/math/Vec2.cpp" "${CURR_DIR}/Render/Primitives/Primitives.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/glfw/deps/glad_gl.c")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/glfw/deps")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Log")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/math")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Shaders")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Render")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/glfw/include")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glfw)

add_executable(${SOURCES})
add_compile_options("$<$<C_COMPILER_ID:GNU>:-std=c++11>")

add_library(render_lib ${SOURCES} ${HEADERS})
target_include_directories(render_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(glfw)