#include <stdio.h>
#include <iostream>
#include "core/filereader.h"

using namespace std;

int main(int argc, char** argv){
    if(argc < 2){
        cout << "No files given, usage:\n\tPyFinder \"files\"" << endl;
        return 0;
    }

    FileReader* fr = new FileReader();

    auto xd = fr->ReadFile(argv[1]);

    return 0;
}