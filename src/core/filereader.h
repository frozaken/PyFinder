#include <string>
#include <vector>

class FileReader{
public:
    FileReader();
    ~FileReader();
    std::vector<std::string>* ReadFile(const std::string&);
};