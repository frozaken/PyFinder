file(GLOB libsrc "*.cpp")
file(GLOB libhdrs "*.h")

add_library(PyFinderCore STATIC ${libsrc} ${libhdrs})

# library that holds test target
add_library(coretestexport "")

target_sources(
    coretestexport
    PRIVATE
        ${libsrc}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/filereader.h
)
target_include_directories(
    coretestexport
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

install(TARGETS PyFinderCore DESTINATION PyFinder/lib)

install(FILES ${PROJECT_SOURCE_DIR}/src/core/filereader.h DESTINATION PyFinder/include)