#include "importresolver.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <regex>
#include <set>

using namespace std;

ImportResolver::ImportResolver(){
    stmtextractor = regex("(?:import ([^ \n;]+) *|from ([^ \n]+) import [^ \n]+)");
}

vector<string>* ImportResolver::ResolveImports(const vector<string>& importstatements){

    set<string>* packs = new set<string>();

    for(vector<string>::const_iterator it = importstatements.begin(); it < importstatements.end(); ++it){
        packs->insert(this->QualifyPackage(*it));
    }

    return new vector<string>(packs->begin(), packs->end());
}

string ImportResolver::QualifyPackage(const string& impstatement){ // needs to be way more advanced
    smatch matches;

    if(!regex_search(impstatement, matches, this->stmtextractor)) return "";
    if(matches[1].length()) return matches[1].str();
    return matches[2].str();
}