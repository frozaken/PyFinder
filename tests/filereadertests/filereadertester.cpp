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

    ASSERT_EQ(lines->size(),1);
    EXPECT_EQ(lines->front(), "import numpy");
}

TEST_F(FileReaderTester, testreadmultiple){

    vector<string>* vec = new vector<string>();

    vec->push_back("testdata/pyfile1.py");
    vec->push_back("testdata/pyfile2.py");

    vector<string>* lines = fr->ReadFiles(*vec);

    ASSERT_EQ(lines->size(),4);
    EXPECT_EQ(lines->at(0), "import numpy; import re\r");
    EXPECT_EQ(lines->at(1), "from math import log2\r");
    EXPECT_EQ(lines->at(2), "print(\"import numpy; import re\")");
    EXPECT_EQ(lines->at(3), "import numpy");
}