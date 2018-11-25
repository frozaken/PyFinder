#include "filereader.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;

FileReader::FileReader(){
    regex strreg = regex("(?:\n|\r)");
}

vector<string>* FileReader::ReadFile(const string& path){

    vector<string>* lines = new vector<string>();

    ifstream file(path);

    string line;

    if(file.is_open()){
        while(getline(file,line)){
            lines->push_back(regex_replace(line, this->strreg, ""));
        }
        file.close();
    }

    return lines;
}

vector<string>* FileReader::ReadFiles(const vector<string>& paths){
    vector<string>* toret = new vector<string>();

    for(vector<string>::const_iterator it = paths.begin(); it < paths.end(); ++it){
        vector<string>* filelines = this->ReadFile(*it);

        toret->insert(toret->begin(), filelines->begin(), filelines->end());
    }

    return toret;
}