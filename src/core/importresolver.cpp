#include "importresolver.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <regex>
#include <set>
#include "pylibs.h"

using namespace std;

ImportResolver::ImportResolver(){
    stmtextractor = regex("(?:import ([^ \n;]+) *|from ([^ \n]+) import [^ \n]+)");
}

vector<string>* ImportResolver::ResolveImports(const vector<string>& importstatements){

    set<string>* packs = new set<string>();

    for(vector<string>::const_iterator it = importstatements.begin(); it < importstatements.end(); ++it){
        string* ptr = this->QualifyPackage(*it);
        if(ptr != nullptr)
            packs->insert(*ptr);
    }

    return new vector<string>(packs->begin(), packs->end());
}

string* ImportResolver::QualifyPackage(const string& impstatement){ // needs to be way more advanced
    smatch matches;
    string* finmatch = new string();

    if(!regex_search(impstatement, matches, this->stmtextractor)) return nullptr;
    if(matches[1].length()) *finmatch = matches[1].str();
    else *finmatch = matches[2].str();

    if(PyLibs::lib36.find(*finmatch) != PyLibs::lib36.end()) return nullptr;

    return finmatch;    
}