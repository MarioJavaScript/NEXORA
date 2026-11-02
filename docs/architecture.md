# Arquitectura de Nexora

## Regla principal

**`native/core` NO depende de Godot.** Ni headers de godot-cpp, ni tipos `godot::*`, ni `Variant`/`String`/`Vector3` de Godot. Solo C++17 estándar.

Así el core se puede compilar y testear con CMake sin el motor, y reutilizar en el servidor dedicado.

## Capas

```
game/ (Godot: escenas, UI, assets)
   │
native/godot_ext/   binding GDExtension (godot-cpp)  ──┐
native/server/      servidor dedicado autoritativo     ├──> native/core  (lógica pura)
native/net/         protocolo + ENet                ───┘
```

- `native/core`: survival, world, mission, inventory, ai. Sin I/O de motor.
- `native/net`: serialización y transporte (ENet). Puede usar `core`, no Godot.
- `native/server`: ejecutable headless; usa `core` + `net`.
- `native/godot_ext`: único lugar donde se mezclan Godot y `core`. Convierte tipos en la frontera.

## Dependencias permitidas

| Módulo      | Puede depender de           |
|-------------|-----------------------------|
| core        | stdlib                      |
| net         | core, ENet                  |
| server      | core, net                   |
| godot_ext   | core, net, godot-cpp        |
