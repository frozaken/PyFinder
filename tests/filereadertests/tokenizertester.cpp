#include "tokenizertester.h"
#include "filereader.h"
#include <string>
#include <vector>
#include <fstream>
#include <limits.h>
#include <stdlib.h>
#include <iostream>
#include <glob.h>
using namespace std;

using ::testing::Return;

TokenizerTester::TokenizerTester(){}

TokenizerTester::~TokenizerTester(){}

void TokenizerTester::SetUp(){
    tkn = new Tokenizer();
}

void TokenizerTester::TearDown(){}

TEST_F(TokenizerTester, testgetstatements){

    vector<string>* lines = new vector<string>();

    lines->push_back("import numpy; import re");

    vector<string>* tokens = tkn->GetStatements(*lines);

    EXPECT_EQ(tokens->size(), 2);
    EXPECT_EQ(tokens->at(0), "import numpy");
    EXPECT_EQ(tokens->at(1), "import re");
}

TEST_F(TokenizerTester, testcomments){
    FileReader* fr = new FileReader();

    auto lines = fr->ReadFile("testdata/pyfile3.py");

    auto statements = tkn->GetStatements(*lines);

    EXPECT_EQ(statements->size(), 1);
    EXPECT_EQ(statements->front(), "import re");
}

TEST_F(TokenizerTester, testgetimports){
    FileReader* fr = new FileReader();

    auto lines = fr->ReadFile("testdata/pyfile2.py");

    auto statements = tkn->GetStatements(*lines);

    EXPECT_EQ(statements->size(), 3);

    auto imports = tkn->FilterImportLines(*statements);

    EXPECT_EQ(imports->size(), 2);
    EXPECT_EQ(imports->at(0), "import numpy");
    EXPECT_EQ(imports->at(1), "import re");
}