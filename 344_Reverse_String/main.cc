#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 36 ms, faster than 99.24% of C++ online submissions for Reverse String.
// Memory Usage: 23.3 MB, less than 60.69% of C++ online submissions for Reverse String.


class Solution {
public:
    void reverseString(std::vector<char>& s) {
        if (s.size() == 0) return;
        char *p = s.data();
        char *rp = s.data() + (s.size() -1);

        while (p < rp) {
            char t = *p;
            *p = *rp;
            *rp = t;

            rp--;
            p++;
        }

    }
};

int main()
{
    std::vector<char> data;
    data.emplace_back('1');
    data.emplace_back('2');
    data.emplace_back('3');
    data.emplace_back('4');
    data.emplace_back('5');


    Solution ss;
    ss.reverseString(data);
    for (int i = 0 ; i < data.size(); i++) {
        printf("%c\n", data[i]);
    }


    return 0;
}