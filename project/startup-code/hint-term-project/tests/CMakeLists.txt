include_directories( ${BF_SOURCE_DIR}/src )
add_library( catch-main catch-main.cpp )
add_executable( test-bf catch-bf.cpp )
target_link_libraries( test-bf catch-main bf )

enable_testing()
add_test(NAME RunTests COMMAND test-bf )
