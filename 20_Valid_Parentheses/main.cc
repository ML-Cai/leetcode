#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>

// ime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 6.3 MB, less than 61.60% of C++ online submissions for Valid Parentheses.

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> ss;
        if (ss.size() %2 != 0) return false;

        auto iter = s.cbegin();
        while (iter != s.cend()) {
            const char &c = *iter;

            if (ss.size() > 0) {
                const char &pattern = ss.top();
                char pair = 'N';
                switch (c) {
                case '}':
                    pair = '{';
                    break;
                case ']':
                    pair = '[';
                    break;
                case ')':
                    pair = '(';
                    break;
                }

                if (pair == pattern) {
                    ss.pop();
                } else {
                    ss.emplace(c);
                }
            } else {
                switch (c) {
                case '}':
                case ']':
                case ')':
                    return false;
                default:
                    ss.emplace(c);
                    break;
                }
            }

            iter++;
        }

        return ss.size() == 0;
    }
};

int main()
{
    Solution ss;

    printf("%d\n", ss.isValid("()()()"));
    printf("%d\n", ss.isValid("((()))"));
    printf("%d\n", ss.isValid("((())))"));
    

    return 0;
}