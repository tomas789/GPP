include_directories(${GPP_SOURCE_DIR}/gpp/include)
include_directories(${GPP_SOURCE_DIR}/libgpp/include)
link_directories(${GPP_SOURCE_DIR}/libgpp/lib)
add_executable(gpp src/main.cpp)
target_link_libraries(gpp libgpp)
