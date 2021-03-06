#include <vector>
#include <string>
#include <regex>

class Tokenizer{
public:
    Tokenizer();
    std::vector<std::string>* GetStatements(const std::vector<std::string>&);
    std::vector<std::string>* FilterImportLines(const std::vector<std::string>&);
private:
    std::regex importre;
    std::regex strreg;
    std::regex mltlncmt;
    inline std::string Trim(const std::string&);
    std::vector<std::string> ProcessLine(const std::string&);
    inline bool StartsWith(const std::string& target, const std::string& start);
};