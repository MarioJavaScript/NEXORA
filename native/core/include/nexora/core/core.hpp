#pragma once

namespace nexora::core {

// Versión del núcleo de juego.
const char* version();

// Función trivial de prueba: limita un valor al rango [lo, hi].
int clamp(int value, int lo, int hi);

} // namespace nexora::core
