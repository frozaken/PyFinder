#include "importresolvertester.h"
#include "filereader.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "tokenizer.h"
using namespace std;

using ::testing::Return;

ImportResolverTester::ImportResolverTester(){}

ImportResolverTester::~ImportResolverTester(){}

void ImportResolverTester::SetUp(){
    irs = new ImportResolver();
}

void ImportResolverTester::TearDown(){}

inline bool isin(const vector<string>& vec, const string& elem){
    return find(vec.begin(), vec.end(), elem) != vec.end();
}

TEST_F(ImportResolverTester, testresolvebasic){

    vector<string> lines = {"import numpy", "import re", "from math import log2"};

    ASSERT_EQ(lines.size(), 3);

    vector<string>* imports = irs->ResolveImports(lines);

    ASSERT_EQ(imports->size(), 1);
    EXPECT_TRUE(isin(*imports, "numpy"));
}

TEST_F(ImportResolverTester, testpyfile1){

    FileReader* fr = new FileReader();

    vector<string>* lines = fr->ReadFile("testdata/pyfile1.py");
    ASSERT_EQ(lines->size(), 1);

    vector<string>* imports = irs->ResolveImports(*lines);

    ASSERT_EQ(imports->size(), 1);
    EXPECT_EQ(imports->at(0), "numpy");
}

TEST_F(ImportResolverTester, testpyfile5){

    Tokenizer* tkn = new Tokenizer();

    FileReader* fr = new FileReader();

    vector<string>* lines = fr->ReadFile("testdata/pyfile5.py");
    ASSERT_EQ(lines->size(), 6);

    lines = tkn->GetStatements(*lines);
    lines = tkn->FilterImportLines(*lines);

    vector<string>* imports = irs->ResolveImports(*lines);

    ASSERT_EQ(imports->size(), 1);
    EXPECT_EQ(imports->at(0), "numpy");
}