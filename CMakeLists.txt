cmake_minimum_required(VERSION 3.25)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(ip-filter VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 20)

configure_file(version.h.in version.h)

add_executable(ip-filter main.cpp)
add_library(version lib.cpp)
add_library(utils utils.cpp)

target_include_directories(version
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(ip-filter PRIVATE
    version
    utils
)

if(WITH_GOOGLE_TEST)
    add_subdirectory(googletest EXCLUDE_FROM_ALL)
    add_executable(test_version test_version.cpp)

    set_target_properties(test_version PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
    )

    target_link_libraries(test_version
        GTest::gtest_main
        version
    )

    add_executable(test_utils test_utils.cpp)

    set_target_properties(test_utils PROPERTIES
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
    )

    target_link_libraries(test_utils
            GTest::gtest_main
            utils
    )
endif()

if (MSVC)
    target_compile_options(ip-filter PRIVATE
        /W4
    )

    target_compile_options(version PRIVATE
        /W4
    )

    if(WITH_GOOGLE_TEST)
        target_compile_options(test_version PRIVATE
            /W4
        )

        target_compile_options(test_utils PRIVATE
                /W4
        )
    endif()
else ()
    target_compile_options(ip-filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )

    target_compile_options(version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )

    if(WITH_GOOGLE_TEST)
        target_compile_options(test_version PRIVATE
            -Wall -Wextra -pedantic -Werror
        )

        target_compile_options(test_utils PRIVATE
                -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

install(TARGETS ip-filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT kruglov.it@gmail.com)
include(CPack)

if(WITH_GOOGLE_TEST)
    enable_testing()
    add_test(test_version test_version)
    add_test(test_utils test_utils)
endif()



