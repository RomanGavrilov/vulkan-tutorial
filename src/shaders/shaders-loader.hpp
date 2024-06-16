#include <fstream>
#include <vector>

class ShadersLoader
{
public:
    static std::vector<char> readFile(const std::string &filename);
};