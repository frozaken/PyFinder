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

    ASSERT_EQ(tokens->size(), 2);
    EXPECT_EQ(tokens->at(0), "import numpy");
    EXPECT_EQ(tokens->at(1), "import re");
}

TEST_F(TokenizerTester, testbasic){
    FileReader* fr = new FileReader();

    auto lines = fr->ReadFile("testdata/pyfile1.py");

    auto statements = tkn->GetStatements(*lines);

    ASSERT_EQ(statements->size(), 1);
    EXPECT_EQ(statements->front(), "import numpy");
}

TEST_F(TokenizerTester, testcomments){
    FileReader* fr = new FileReader();

    auto lines = fr->ReadFile("testdata/pyfile3.py");

    auto statements = tkn->GetStatements(*lines);

    ASSERT_EQ(statements->size(), 1);
    EXPECT_EQ(statements->front(), "import re");
}

TEST_F(TokenizerTester, testincodestring){
    FileReader* fr = new FileReader();

    auto lines = fr->ReadFile("testdata/pyfile2.py");

    auto statements = tkn->GetStatements(*lines);

    ASSERT_EQ(statements->size(), 4);
    EXPECT_EQ(statements->at(0), "import numpy");
    EXPECT_EQ(statements->at(1), "import re");
    EXPECT_EQ(statements->at(2), "from math import log2");
}

TEST_F(TokenizerTester, testgetimports){
    FileReader* fr = new FileReader();

    auto lines = fr->ReadFile("testdata/pyfile2.py");

    auto statements = tkn->GetStatements(*lines);

    ASSERT_EQ(statements->size(), 4);
    
    auto imports = tkn->FilterImportLines(*statements);

    ASSERT_EQ(imports->size(), 3);
    EXPECT_EQ(imports->at(0), "import numpy");
    EXPECT_EQ(imports->at(1), "import re");
    EXPECT_EQ(imports->at(2), "from math import log2");
}

TEST_F(TokenizerTester, testimportmulicomment){
    FileReader* fr = new FileReader();

    auto lines = fr->ReadFile("testdata/pyfile4.py");

    auto statements = tkn->GetStatements(*lines);

    ASSERT_EQ(statements->size(), 1);
    
    auto imports = tkn->FilterImportLines(*statements);

    ASSERT_EQ(imports->size(), 1);
    EXPECT_EQ(imports->at(0), "import re");
}