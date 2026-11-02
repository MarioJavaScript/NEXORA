#include "nexora/core/core.hpp"

namespace nexora::core {

const char* version() {
    return "0.0.1";
}

int clamp(int value, int lo, int hi) {
    if (value < lo) {
        return lo;
    }
    if (value > hi) {
        return hi;
    }
    return value;
}

} // namespace nexora::core
