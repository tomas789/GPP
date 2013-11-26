include_directories(${GPP_SOURCE_DIR}/libgpp/include)

SET(LIBRARY_OUTPUT_PATH ${GPP_BINARY_DIR}/libgpp/lib)

set (SRC_FILES src/libgpp.cpp src/Exception.cpp)

set (TEST_FILES tests/Exception.cpp)

add_library(libgpp ${SRC_FILES})
set_target_properties(libgpp PROPERTIES PREFIX "")

enable_testing()

include_directories(${GTEST_INCLUDE_DIR} ${GPP_SOURCE_DIR}/libgpp/include)

message (STATUS "GTEST_INCLUDE_DIR: " ${GTEST_INCLUDE_DIR})
message (STATUS "LIBGPP INCLUDE: " ${GPP_SOURCE_DIR}/libgpp/include)

add_executable (libgpp-test ${SRC_FILES} ${TEST_FILES})
add_dependencies(libgpp-test googletest)

ExternalProject_Get_Property(googletest binary_dir)
target_link_libraries(libgpp-test gtest_main gtest)
add_test(NAME libgpp-main-tests COMMAND libgpp-test)

install (FILES DESTINATION ${GPP_SOURCE_DIR}/lib)
