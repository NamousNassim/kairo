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

find_package(Python COMPONENTS Interpreter REQUIRED)

set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
set(GLAD_API "gl=3.3" CACHE STRING "OpenGL API version")
set(GLAD_GENERATOR "c" CACHE STRING "GLAD generator")
set(GLAD_REPRODUCIBLE ON CACHE BOOL "Use GLAD's bundled OpenGL specifications")
set(GLAD_INSTALL OFF CACHE BOOL "Generate GLAD installation rules")

FetchContent_Declare(glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG 1ecd45775d96f35170458e6b148eb0708967e402 # GLAD 0.1.36
)
# GLAD 1 declares compatibility with CMake 3.0, which CMake 4 no longer accepts.
block(SCOPE_FOR VARIABLES)
    set(CMAKE_POLICY_VERSION_MINIMUM 3.10)
    set(BUILD_SHARED_LIBS OFF)
    FetchContent_MakeAvailable(glad)
endblock()
target_link_libraries(glad PRIVATE ${CMAKE_DL_LIBS})

add_subdirectory(engine)
add_subdirectory(apps/sandbox)
