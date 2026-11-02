#include <doctest/doctest.h>

#include <string>

#include "nexora/core/core.hpp"

TEST_CASE("core: version") {
    CHECK(std::string(nexora::core::version()) == "0.0.1");
}

TEST_CASE("core: clamp") {
    CHECK(nexora::core::clamp(5, 0, 10) == 5);
    CHECK(nexora::core::clamp(-3, 0, 10) == 0);
    CHECK(nexora::core::clamp(42, 0, 10) == 10);
}
