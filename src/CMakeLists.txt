add_executable(PyFinder main.cpp)

add_subdirectory(core)

target_link_libraries(PyFinder PyFinderCore)
target_include_directories(PyFinder PRIVATE ${PROJECT_BINARY_DIR})

install(TARGETS PyFinder DESTINATION PyTest/bin)