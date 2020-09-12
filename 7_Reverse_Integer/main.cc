#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
// Memory Usage: 5.8 MB, less than 97.36% of C++ online submissions for Reverse Integer.


class Solution {
public:
    int reverse(int x) {
        int64_t counter = 0;

        bool inv = false;
        if (x < 0) {
            x = abs(x);
            inv = true;
        }

        while (x > 0) {
            int c = x % 10;
            x = x / 10;

            counter = counter * 10 + c;

            // check ov
            if (counter > INT32_MAX) {
                return 0;
            }
        }

        if (inv)
            return -counter;
        else
            return counter;
    }
};

int main()
{
    Solution ss;

    printf("%d\n", ss.reverse(333));
    printf("%d\n", ss.reverse(123456789));
    printf("%d\n", ss.reverse(123));
    printf("%d\n", ss.reverse(-123));
    printf("%d\n", ss.reverse(120));
    printf("%d\n", ss.reverse(1534236469));
    
    return 0;
}