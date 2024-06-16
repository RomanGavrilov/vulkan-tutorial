cmake_minimum_required(VERSION 3.12)
project(arcticSky)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glm)

find_package(Vulkan REQUIRED)

add_executable(
    arcticSky 
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/shaders/shaders-loader.cpp
) 

target_link_libraries(arcticSky glfw)
target_link_libraries(arcticSky glm)
target_link_libraries(arcticSky Vulkan::Vulkan)



