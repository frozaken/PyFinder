#include <vector>
#include <string>
#include "tokenizer.h"
#include "importresolver.h"
#include "filereader.h"

class PyFinder{
private:
    ImportResolver* irs;
    Tokenizer* tkn;
    FileReader* fr;
public:
    PyFinder();
    std::vector<std::string>* FindPackages(const std::string& file);
    std::vector<std::string>* FindPackages(const std::vector<std::string>& files);
};