#include <string>
#include <vector>
#include <regex>

class FileReader{
private:
    std::regex strreg;
public:
    FileReader();
    ~FileReader();
    std::vector<std::string>* ReadFile(const std::string&);
    std::vector<std::string>* ReadFiles(const std::vector<std::string>&);
};