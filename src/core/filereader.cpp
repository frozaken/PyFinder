#include "filereader.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<string>* FileReader::ReadFile(const string& path){

    vector<string>* lines = new vector<string>();

    ifstream file(path);

    string line;

    if(file.is_open()){
        while(getline(file,line)){
            lines->push_back(line);
        }
        file.close();
    }

    return lines;
}

FileReader::FileReader(){

}