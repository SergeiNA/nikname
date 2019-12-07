cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(ENV{TRAVIS_BUILD_NUMBER} 777)
endif()

project(nikname VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(nikname nikname.cpp radixTrie.h radixTrie.cpp)

add_executable(test_main_en test_main_en.cpp radixTrie.h radixTrie.cpp)
add_executable(test_main_ru test_main_ru.cpp radixTrie.h radixTrie.cpp)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set_target_properties(nikname test_main_en test_main_ru PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(test_main_en test_main_ru PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(nikname
    Threads::Threads
)

target_link_libraries(test_main_en
    Threads::Threads
    ${Boost_LIBRARIES}
)

target_link_libraries(test_main_ru
    Threads::Threads
    ${Boost_LIBRARIES}
)

install(TARGETS nikname RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT "SergeiNA at github.com")

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(main_tests_en test_main_en)
add_test(main_tests_ru test_main_ru)