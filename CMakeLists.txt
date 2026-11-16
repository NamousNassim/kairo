cmake_minimum_required(VERSION 3.28)
project(kairo VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build GLFW documentation" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build GLFW examples" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build GLFW tests" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "Generate GLFW installation rules" FORCE)
set(GLFW_LIBRARY_TYPE STATIC CACHE STRING "GLFW library type" FORCE)

FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 70a9bb3881fe80fd483236e2b203cb451c6ecf40 # GLFW 3.5.1
)
FetchContent_MakeAvailable(glfw)

add_subdirectory(engine)
add_subdirectory(apps/sandbox)
