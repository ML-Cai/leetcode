#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 6.5 MB, less than 85.25% of C++ online submissions for Letter Combinations of a Phone Number.

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::string::const_iterator iter = digits.cbegin();
        std::vector<std::string> list_0;
        std::vector<std::string> list_1;

        if (digits.size() == 0) return list_0;

        list_0.emplace_back("");

        std::vector<std::string> *p_list_A = &list_0;
        std::vector<std::string> *p_list_B = &list_1;

        while (iter != digits.end()) {
            char *p = this->get_pattern(*iter);
            auto iter_fetch = p_list_A->cbegin();

            p_list_B->clear();

            while (iter_fetch != p_list_A->cend()) {
                for (int ci = 0 ; ci < 4 ; ci ++) {
                    if (p[ci] == 0) break;

                    p_list_B->emplace_back(*iter_fetch + p[ci]);
                }
                iter_fetch++;
            }

            std::vector<std::string> *tmp = p_list_A;
            p_list_A = p_list_B;
            p_list_B = tmp;
            iter++;
        }

        return *p_list_A;
    }

    char * get_pattern(const int c) const {

        static char p[][5]  = {"abc",
                        "def",
                        "ghi",
                        "jkl",
                        "mno",
                        "pqrs",
                        "tuv",
                        "wxyz"};
        switch (c) {
            case '2': return p[0];
            case '3': return p[1];
            case '4': return p[2];
            case '5': return p[3];
            case '6': return p[4];
            case '7': return p[5];
            case '8': return p[6];
            case '9': return p[7];
        }
        return nullptr;
    }
};

int main()
{
    Solution ss;

    std::vector<std::string> ret = ss.letterCombinations("2");

    for (int i = 0 ; i < ret.size(); i++) {
        printf("%s\n", ret[i].c_str());
    }

    return 0;
}