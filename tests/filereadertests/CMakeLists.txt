file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testpyfinder ${SRCS})

TARGET_LINK_LIBRARIES(testpyfinder libgtest libgmock coretestexport)


add_test(NAME 
            testpyfinder
         COMMAND 
            testpyfinder
        WORKING_DIRECTORY
            ${PROJECT_BINARY_DIR}) #to get testdata