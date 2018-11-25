#include "filereadertester.h"
#include <string>
#include <vector>
#include <fstream>
#include <limits.h>
#include <stdlib.h>
#include <iostream>
#include <glob.h>
using namespace std;

using ::testing::Return;

FileReaderTester::FileReaderTester(){}

FileReaderTester::~FileReaderTester(){}

void FileReaderTester::SetUp(){
    fr = new FileReader();
}

void FileReaderTester::TearDown(){}

TEST_F(FileReaderTester, testreadline){

    string testfile = "testdata/pyfile1.py";
    vector<string>* lines = fr->ReadFile(testfile);

    EXPECT_EQ(lines->size(),1);
    EXPECT_EQ(lines->front(), "import numpy");
}