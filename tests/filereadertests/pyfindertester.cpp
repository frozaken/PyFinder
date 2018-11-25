#include "pyfindertester.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

using ::testing::Return;

inline bool isin(const vector<string>& vec, const string& elem){
    return find(vec.begin(), vec.end(), elem) != vec.end();
}

PyFinderTester::PyFinderTester(){}

PyFinderTester::~PyFinderTester(){}

void PyFinderTester::SetUp(){
    pf = new PyFinder();
}

void PyFinderTester::TearDown(){}

TEST_F(PyFinderTester, testfullflow1){
    vector<string>* packs = pf->FindPackages("testdata/pyfile1.py");

    ASSERT_EQ(packs->size(),1);
    EXPECT_EQ(packs->at(0), "numpy");
}

TEST_F(PyFinderTester, testfullflow2){
    vector<string>* packs = pf->FindPackages("testdata/pyfile2.py");

    ASSERT_EQ(packs->size(),1);
    EXPECT_TRUE(isin(*packs, "numpy"));
}

TEST_F(PyFinderTester, testfullflow3){
    vector<string>* packs = pf->FindPackages("testdata/pyfile3.py");

    ASSERT_EQ(packs->size(),0);
}

TEST_F(PyFinderTester, testfullflow4){
    vector<string>* packs = pf->FindPackages("testdata/pyfile4.py");

    ASSERT_EQ(packs->size(),0);
}