cmake_minimum_required(VERSION 3.14)

project(VariantTest VERSION 1.0.0.0 LANGUAGES CXX)

add_executable(
    variant-test
    main.cpp
    kinds.hpp
    oo/factory.hpp
    variant/factory.hpp
)
target_include_directories(
    variant-test
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
set_target_properties(
    variant-test
    PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)


# Installing
include(CMakePackageConfigHelpers)

add_executable(VariantTest::variant-test ALIAS variant-test)
configure_package_config_file(
    "VariantTestConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/VariantTestConfig.cmake"
    INSTALL_DESTINATION lib/cmake/VariantTest
)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/VariantTestConfigVersion.cmake"
    VERSION ${VariantTest_VERSION}
    COMPATIBILITY SameMajorVersion
)
install(
    TARGETS variant-test EXPORT VariantTestTargets
    RUNTIME DESTINATION bin
)
install(
    EXPORT VariantTestTargets
    FILE VariantTestTargets.cmake
    NAMESPACE VariantTest::
    DESTINATION lib/cmake/VariantTest
)
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/VariantTestConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/VariantTestConfigVersion.cmake"
    DESTINATION lib/cmake/VariantTest
)


# Packaging
set(CPACK_PACKAGE_VENDOR "matek")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Testing variant vs typical OO")
set(CPACK_PACKAGE_CONTACT "matek_a@outlook.com")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

include(CPack)