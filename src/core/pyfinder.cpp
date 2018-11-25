#include "pyfinder.h"
#include <string>
#include <vector>

using namespace std;

PyFinder::PyFinder(){
    fr = new FileReader();
    irs = new ImportResolver();
    tkn = new Tokenizer();
}

vector<string>* PyFinder::FindPackages(const string& file){
    vector<string>* lns = fr->ReadFile(file);
    lns = tkn->GetStatements(*lns);
    lns = tkn->FilterImportLines(*lns);
    lns = irs->ResolveImports(*lns);

    return lns;
}

vector<string>* PyFinder::FindPackages(const vector<string>& files){
    vector<string>* lns = fr->ReadFiles(files);
    lns = tkn->GetStatements(*lns);
    lns = tkn->FilterImportLines(*lns);
    lns = irs->ResolveImports(*lns);

    return lns;
}