file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testpyfinder ${SRCS})

TARGET_LINK_LIBRARIES(testpyfinder libgtest libgmock PyFinderT)


add_test(NAME 
            testpyfinder
         COMMAND 
            testpyfinder)