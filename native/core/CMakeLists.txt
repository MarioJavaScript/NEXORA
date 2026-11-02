# nexora_core: lógica pura de juego. NO depende de Godot.
add_library(nexora_core STATIC
    src/core.cpp
)
add_library(nexora::core ALIAS nexora_core)

target_include_directories(nexora_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(nexora_core PUBLIC cxx_std_17)

if(MSVC)
    target_compile_options(nexora_core PRIVATE /W4 /permissive-)
else()
    target_compile_options(nexora_core PRIVATE -Wall -Wextra -Wpedantic)
endif()
