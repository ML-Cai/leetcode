#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 4 ms, faster than 99.06% of C++ online submissions for Palindrome Number.
// Memory Usage: 6.1 MB, less than 26.73% of C++ online submissions for Palindrome Number.

class Solution {
public:
    bool isPalindrome(int x) {
        bool ret = false;

        if (x < 0) return false;
        if (x < 10) return true;
        if (x % 10 == 0) return false;

        int ac = 0;

        while (x > ac) {
            ac = ac * 10 + x % 10;

            if (ac == x) {
                return true;
            }
            x /= 10;
        }

        if (ac == x) {
            ret = true;
        }

        return ret;
    }
};

int main()
{
    Solution ss;

    printf("%d\n", ss.isPalindrome(10));
    printf("%d\n", ss.isPalindrome(11));
    printf("%d\n", ss.isPalindrome(1234));
    printf("%d\n", ss.isPalindrome(-1234));
    printf("%d\n", ss.isPalindrome(121));
    printf("%d\n", ss.isPalindrome(-121));
    printf("%d\n", ss.isPalindrome(12321));
    return 0;
}