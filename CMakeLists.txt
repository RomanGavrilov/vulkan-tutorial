cmake_minimum_required(VERSION 3.12)
project(simpleStamp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glm)

find_package(Vulkan REQUIRED)

add_executable(
    simpleStamp 
    src/main.cpp
) 

target_link_libraries(simpleStamp glfw)
target_link_libraries(simpleStamp glm)
target_link_libraries(simpleStamp Vulkan::Vulkan)



