#include <iostream>
#include <cassert>
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

    std::optional<std::vector<std::string>> split_const(const std::string& str, const char delimiter)
    {

        if (str.length() == 0) { return {}; }

        std::vector<uint> histogram;
        histogram.reserve(str.length());

        for (const auto& ch : str)
        {
            histogram.push_back(delimiter == ch ? 1 : 0);
        }

        for (int i=1; i<histogram.size(); i++)
        {
            histogram[i] = histogram[i] + histogram[i-1]; 
        }

        auto last_index = histogram.back();

        // The return value.
        auto result = std::make_optional<std::vector<std::string>>(last_index+1, std::string());

        for (int i=0; i<histogram.size(); i++)
        {
            if (str[i] != '\t')
            {
               (*result)[histogram[i]].push_back(str[i]); 
            }
        }

        if ((*result).size() != 17) { return {}; }

        return result;
    }
} // namespace
