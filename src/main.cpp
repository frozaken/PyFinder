#include <stdio.h>
#include <iostream>
#include "core/pyfinder.h"

using namespace std;

int main(int argc, char** argv){
    if(argc < 2){
        cout << "No files given, usage:\n\tPyFinder \"files\"" << endl;
        return 0;
    }

    PyFinder* pf = new PyFinder();

    vector<string>* files = new vector<string>();

    for(int i = 1; i < argc; ++i){
        files->push_back(argv[i]);
    }

    vector<string>* packs = pf->FindPackages(*files);

    for(vector<string>::iterator it = packs->begin(); it < packs->end(); ++it){
        cout << *it << "\n";
    }

    return 0;
}