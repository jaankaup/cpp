#include "misc.h"

namespace Misc {
    
    std::vector<std::string> split(std::string str, const std::string& delimiter)
    {
        std::vector<std::string> result;

        size_t pos = 0;
        
        while ((pos = str.find(delimiter)) != std::string::npos) {
            std::string token = str.substr(0, pos);
            result.push_back(token);
            str.erase(0, pos + delimiter.length());
        }

        return result;
    }

} // namespace
