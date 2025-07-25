cmake_minimum_required(VERSION 3.28)

project(simplelogs LANGUAGES CXX)
include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# https://stackoverflow.com/questions/53499678/cmake-build-shared-libs-for-single-libraries
option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static (.lib/.a)" OFF)

set(SOURCES
    src/logs.cpp
)
set(HEADERS
    include/logs.h
)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

FetchContent_Declare(
	spdlog
	GIT_REPOSITORY https://github.com/gabime/spdlog
	GIT_TAG v1.x
)

FetchContent_MakeAvailable(spdlog)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog)