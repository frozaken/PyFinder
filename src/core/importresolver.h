#include <vector>
#include <string>
#include <regex>

class ImportResolver{
private:
    std::string* QualifyPackage(const std::string&);
    std::regex stmtextractor;
public:
    ImportResolver();
    std::vector<std::string>* ResolveImports(const std::vector<std::string>& importstatements);
    bool BinarySearch(const std::vector<std::string>& vec, std::string pack);
};