add_library(kairo_engine STATIC
    src/Application.cpp
    src/GLFWSystem.cpp
    src/Window.cpp
    src/engine.cpp
)
add_library(Kairo::Engine ALIAS kairo_engine)

target_link_libraries(kairo_engine PUBLIC glfw)
target_compile_definitions(kairo_engine PUBLIC GLFW_INCLUDE_NONE)

target_compile_features(kairo_engine PUBLIC cxx_std_20)
set_target_properties(kairo_engine PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(kairo_engine
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
