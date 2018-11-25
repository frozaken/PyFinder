file(GLOB libsrc "*.cpp")
file(GLOB libhdrs "*.h")

add_library(pyfindercore STATIC)


# library that holds test target

target_sources(
    pyfindercore
   PRIVATE
        ${libsrc}
    PUBLIC
        ${libhdrs}
)
target_include_directories(
    pyfindercore
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

install(TARGETS pyfindercore DESTINATION pyfinder/lib)

install(FILES ${PROJECT_SOURCE_DIR}/src/core/filereader.h DESTINATION pyfinder/include)