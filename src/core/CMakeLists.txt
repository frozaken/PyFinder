file(GLOB libsrc "*.cpp")
file(GLOB libhdrs "*.h")

add_library(PyFinderCore STATIC ${libsrc} ${libhdrs})

# library that holds test target
add_library(PyFinderT "")

target_sources(
    PyFinderT
    PRIVATE
        ${libsrc}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/filereader.h
)
target_include_directories(
    PyFinderT
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

install(TARGETS PyFinderCore DESTINATION PyFinder/lib)

install(FILES ${PROJECT_SOURCE_DIR}/src/core/filereader.h DESTINATION PyFinder/include)