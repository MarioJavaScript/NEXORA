include(FetchContent)

FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    GIT_TAG v2.4.11
    GIT_SHALLOW TRUE
)
set(DOCTEST_NO_INSTALL ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(doctest)

add_executable(nexora_tests
    test_main.cpp
    core/test_core.cpp
)

target_link_libraries(nexora_tests PRIVATE nexora::core doctest::doctest)

add_test(NAME nexora_tests COMMAND nexora_tests)
