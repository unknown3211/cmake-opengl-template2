cmake_minimum_required(VERSION 3.30)

if(MSVC)
   set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>")
endif()

project(testproject)
file(GLOB_RECURSE MY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(${CMAKE_PROJECT_NAME} "${MY_SOURCES}")
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/" "${CMAKE_CURRENT_SOURCE_DIR}/libs/simplelogs/include")
target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")

if(UNIX AND NOT APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE m pthread dl rt X11)
endif()

add_subdirectory(libs/glfw-3.4)
add_subdirectory(libs/glad)
add_subdirectory(libs/simplelogs)
add_subdirectory(libs/imgui-docking)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glfw glad simplelogs imgui)