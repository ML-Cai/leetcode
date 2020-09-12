#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// strange performance.... be one of following test:
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 6.3 MB, less than 45.62% of C++ online submissions for String to Integer (atoi).

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 6.3 MB, less than 45.62% of C++ online submissions for String to Integer (atoi).

class Solution {
public:
    int myAtoi(std::string str) {
        int ret = 0;

        do {
            std::string::const_iterator iter = str.cbegin();
            while (iter != str.cend() && *iter== ' ') {    // remove white
                iter++;
            }

            if (iter == str.cend()) {
                break;
            }

            bool is_negative = false;
            switch (*iter) {
                case '-':
                    is_negative = true;
                case '+':
                    iter++;
                    break;
            }

            int64_t val = 0;
            while (iter != str.cend()) {
                int64_t tmp = this->getSumIntValue(val, *iter);

                if (tmp < 0) {  // noe-digit number
                    break;
                } else {
                    val = tmp;
                    if (val > INT32_MAX) break;
                }
                iter++;
            }

            if (is_negative) {
                val = -val;
            }

            if (val > INT32_MAX) {
                ret = INT32_MAX;
            } else if (val < INT32_MIN) {
                ret = INT32_MIN;
            } else {
                ret = static_cast<int32_t>(val);
            }

        } while (false);

        return ret;
    }

 private:
    const int64_t getSumIntValue(const int64_t &base, const char & c) const {
        switch (c) {
            case '0': return base * 10;
            case '1': return base * 10 + 1;
            case '2': return base * 10 + 2;
            case '3': return base * 10 + 3;
            case '4': return base * 10 + 4;
            case '5': return base * 10 + 5;
            case '6': return base * 10 + 6;
            case '7': return base * 10 + 7;
            case '8': return base * 10 + 8;
            case '9': return base * 10 + 9;
            default:
                return -1;
        }
    }
};


int main()
{
    Solution ss;

    printf("%d\n", ss.myAtoi("-91283472332"));
    printf("%d\n", ss.myAtoi("3.141"));
    printf("%d\n", ss.myAtoi("42"));
    printf("%d\n", ss.myAtoi("   -42"));
    printf("%d\n", ss.myAtoi("4193 with words"));
    printf("%d\n", ss.myAtoi("-4193 with words"));
    printf("%d\n", ss.myAtoi("-91283472332"));
    printf("%d\n", ss.myAtoi("words and 987"));
    printf("%d\n", ss.myAtoi("-words and 987"));

    return 0;
}