# Nexora

Survival cooperativo en primera persona. Exploración, recolección, construcción y supervivencia en grupo dentro de un bosque hostil.

## Stack

- **Motor:** Godot 4
- **Lógica:** C++17 vía GDExtension (godot-cpp)
- **Red:** servidor autoritativo con ENet
- **Build:** CMake (core + tests), SCons (GDExtension)
- **Tests:** doctest

## Estructura

```
docs/               documentación (ver docs/architecture.md)
game/               proyecto Godot (scenes, ui, assets)
native/core/        lógica pura C++ (survival, world, mission, inventory, ai) — sin Godot
native/net/         red / protocolo (ENet)
native/godot_ext/   binding GDExtension (SCons + godot-cpp)
native/server/      servidor dedicado
data/               datos de juego (tablas, configs)
tools/              scripts y utilidades
tests/              tests C++ (doctest)
third_party/        dependencias externas (godot-cpp, ENet)
.github/workflows/  CI
```

## Requisitos (Windows)

- Visual Studio 2022+ Build Tools con la carga "Desarrollo para el escritorio con C++" (MSVC)
- CMake 3.21+
- Git (FetchContent descarga doctest)
- Godot 4.x
- Python + SCons (para la GDExtension, más adelante)

## Compilar core y correr tests

Desde una "Developer PowerShell for VS":

```powershell
cmake -S . -B build
cmake --build build --config Debug
ctest --test-dir build -C Debug --output-on-failure
```

## GDExtension

Pendiente: `native/godot_ext/SConstruct` es un placeholder hasta agregar godot-cpp.
