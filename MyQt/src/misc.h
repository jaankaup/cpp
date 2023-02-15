#ifndef MISC
#define MISC

#include<vector>
#include<string>
#include <optional>

namespace Misc {

    extern std::vector<std::string> split(std::string& str, const std::string& delimiter);
    extern std::optional<std::vector<std::string>> split_const(const std::string& str, const char delimiter);

} // namespace

#endif // MISC
