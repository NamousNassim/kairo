add_library(kairo_engine STATIC
    src/Application.cpp
    src/engine.cpp
)
add_library(Kairo::Engine ALIAS kairo_engine)

target_compile_features(kairo_engine PUBLIC cxx_std_20)
set_target_properties(kairo_engine PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(kairo_engine
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
