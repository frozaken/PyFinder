add_executable(pyfinder main.cpp)

add_subdirectory(core)

target_link_libraries(pyfinder pyfindercore)
target_include_directories(pyfinder PRIVATE ${PROJECT_BINARY_DIR})

install(TARGETS pyfinder DESTINATION pyfinder/bin)

install(TARGETS pyfinder DESTINATION bin)