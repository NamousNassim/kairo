add_executable(kairo_sandbox
    src/main.cpp
)

target_link_libraries(kairo_sandbox PRIVATE Kairo::Engine)
set_target_properties(kairo_sandbox PROPERTIES CXX_EXTENSIONS OFF)
