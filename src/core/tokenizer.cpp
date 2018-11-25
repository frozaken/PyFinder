#include "tokenizer.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

Tokenizer::Tokenizer(){}

vector<string>* Tokenizer::GetStatements(const vector<string>& lines){
    vector<string>* tokens = new vector<string>();

    bool incomment = false;
    regex mltlncmt("\"\"\"");

    for(vector<string>::const_iterator it = lines.begin(); it < lines.end(); ++it){
        if(this->StartsWith(*it, "#")) continue;
        if(regex_match(this->Trim(*it),mltlncmt)){
            incomment = !incomment;
            continue;
        }
        if(incomment) continue;
        vector<string> p_res = this->ProcessLine(*it);
        tokens->insert(tokens->end(), p_res.begin(), p_res.end());
    }

    return tokens;
}

vector<string>* Tokenizer::FilterImportLines(const vector<string>& statements){
    vector<string>* importstatements = new vector<string>();

    regex importre("(import [^ \n]+|from [^ \n]+ import [^ \n]+)");
    for(vector<string>::const_iterator it = statements.begin(); it < statements.end(); ++it){
            if(regex_match(*it, importre))
                importstatements->push_back(*it);
    }
    return importstatements;
}

inline bool Tokenizer::StartsWith(const string& target, const string& start){
    return this->Trim(target).find(start) == 0;
}

inline string Tokenizer::Trim(const string &s)
{
   auto wsfront = find_if_not(s.begin(),s.end(),[](int c){
        return isspace(c);
       });
   return string(wsfront,
                find_if_not(s.rbegin(),string::const_reverse_iterator(wsfront),
                [](int c){
                    return isspace(c);
                    }).base());
}

vector<string> Tokenizer::ProcessLine(const string& line){

    vector<string>* toks = new vector<string>();
    size_t spos = 0;
    string toadd;

    regex strreg("[\"'][^\"\']*[\"\']");

    string nostrline = regex_replace(line, strreg, "");

    for(size_t i = 0; i < nostrline.length(); ++i){
        if(nostrline[i] == ';' || i == nostrline.length() - 1){
            toadd = this->Trim(nostrline.substr(spos,i++));
            spos = i+1;
            toks->push_back(toadd);
        }
    }

    return *toks;
}