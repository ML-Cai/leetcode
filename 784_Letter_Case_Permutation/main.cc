#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 4 ms, faster than 99.90% of C++ online submissions for Letter Case Permutation.
// Memory Usage: 9.9 MB, less than 74.75% of C++ online submissions for Letter Case Permutation.

class Solution {
public:
    const char getInvCase(const char & c) const {
        switch (c) {
            case 'A': return 'a';
            case 'B': return 'b';
            case 'C': return 'c';
            case 'D': return 'd';
            case 'E': return 'e';
            case 'F': return 'f';
            case 'G': return 'g';
            case 'H': return 'h';
            case 'I': return 'i';
            case 'J': return 'j';
            case 'K': return 'k';
            case 'L': return 'l';
            case 'M': return 'm';
            case 'N': return 'n';
            case 'O': return 'o';
            case 'P': return 'p';
            case 'Q': return 'q';
            case 'R': return 'r';
            case 'S': return 's';
            case 'T': return 't';
            case 'U': return 'u';
            case 'V': return 'v';
            case 'W': return 'w';
            case 'X': return 'x';
            case 'Y': return 'y';
            case 'Z': return 'z';

            case 'a': return 'A';
            case 'b': return 'B';
            case 'c': return 'C';
            case 'd': return 'D';
            case 'e': return 'E';
            case 'f': return 'F';
            case 'g': return 'G';
            case 'h': return 'H';
            case 'i': return 'I';
            case 'j': return 'J';
            case 'k': return 'K';
            case 'l': return 'L';
            case 'm': return 'M';
            case 'n': return 'N';
            case 'o': return 'O';
            case 'p': return 'P';
            case 'q': return 'Q';
            case 'r': return 'R';
            case 's': return 'S';
            case 't': return 'T';
            case 'u': return 'U';
            case 'v': return 'V';
            case 'w': return 'W';
            case 'x': return 'X';
            case 'y': return 'Y';
            case 'z': return 'Z';
            
            default: return c;
        }

    }

    void sub_task(const size_t op_idx,
                  char *pad_s,
                  std::vector<std::string> *ret) const {
        
        const char c = *pad_s;
        if (c == 0) {
            ret->emplace_back(std::string(pad_s - op_idx));
        } else {
            sub_task(op_idx + 1, pad_s + 1, ret);

            const char nc = getInvCase(c);
            if (nc != c) {
                *pad_s = nc;
                sub_task(op_idx + 1, pad_s + 1, ret);
            }
        }
    }

    std::vector<std::string> letterCasePermutation(std::string S) {
        // "a1b2"
        std::string pad_s;
        std::vector<std::string> ret;
        pad_s = S;
        sub_task(0, (char *)pad_s.data(), &ret);

        return ret;
    }
};

int main()
{
    Solution ss;
    std::vector<std::string> ret = ss.letterCasePermutation("a1b2");

    for (int i = 0 ; i < ret.size(); i++) {
        printf("[%s]\n", ret[i].c_str());
    }

 
    return 0;
}