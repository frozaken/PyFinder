#include "filereadertester.h"

using ::testing::Return;

FileReaderTester::FileReaderTester(){}

FileReaderTester::~FileReaderTester(){}

void FileReaderTester::SetUp(){
    fr = new FileReader();
}

void FileReaderTester::TearDown(){}


TEST_F(FileReaderTester, testcall){
    EXPECT_EQ(1,1); //lets just check something trivial
}