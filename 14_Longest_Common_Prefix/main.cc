#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string ret = "";
        if (strs.size() ==0) return ret;
        if (strs.size() ==1) return strs[0];

        for (size_t i = 0 ; i < strs[0].size() ; i++) {
            const char &pattern = strs[0][i];

            auto iter = strs.begin();
            iter++;
            while (iter != strs.end()) {
                const std::string &ss = *iter;
                if (pattern != ss[i]) {
                    return strs[0].substr(0, i);
                }
                iter++;
            }
        }

        return strs[0];

        // std::string ret = "";
        // if (strs.size() ==0) return ret;
        // if (strs.size() ==1) return strs[0];

        // bool b_exit = false;

        // for (size_t i = 0 ; !b_exit && i < strs[0].size() ; i++) {
        //     const char pattern = strs[0][i];

        //     auto iter = strs.begin();
        //     iter++;
        //     while (!b_exit && iter != strs.end()) {
        //         const std::string &ss = *iter;
        //         if (pattern != ss[i]) {
        //             b_exit = true;
        //         }
        //         iter++;
        //     }

        //     if (!b_exit) ret += pattern;
        // }

        // return ret;
    }
};

int main()
{
    std::vector<std::string> data;
    data.emplace_back("fldower");
    data.emplace_back("fldower");
    data.emplace_back("fldower");
    // data.emplace_back("");
    // data.emplace_back("");

    Solution ss;
    printf(">%s<\n", ss.longestCommonPrefix(data).c_str());

    return 0;
}