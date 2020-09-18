#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <unordered_map>
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sqrt(x).
// Memory Usage: 5.9 MB, less than 61.22% of C++ online submissions for Sqrt(x).

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        
        int64_t vA = 0;
        int64_t vB = x / 2 + 1;

        // 0 1 2 3 4 5
        //     2   4
        //     2 3 4 5
        //       3         9
        //     2 3
        
        
        // 0 1 2
        // 0 1  2

        
        while ((vB - vA) > 1) {
            int64_t vC = (vA + vB) / 2;
            int64_t vC_2 = vC * vC;
            
            if (vC_2 > x) {
                vB = vC;
            } else if (vC_2 < x) {
                vA = vC;
            } else {
                return vC;
            }
        }
        
        return vA;
    }
};

int main()
{
    printf(">%d<\n", 1 % 2);
    printf(">%d<\n", 0 % 2);
    Solution ss;
    printf("%d\n ", ss.mySqrt(0));
    printf("%d\n ", ss.mySqrt(1));
    printf("%d\n ", ss.mySqrt(2));
    printf("%d\n ", ss.mySqrt(3));
    printf("%d\n ", ss.mySqrt(4));
    printf("%d\n ", ss.mySqrt(5));
    printf("%d\n ", ss.mySqrt(9));
// "1010"
// "1011"
    // "1111101110010100110101101001001100011101111000101010 101011111011100111100101100111"
    // "1111101110010100110101101001001100011101111000101010 0101011111011100111100101100111"
        // 1111101110010100110101101001001100011101111000101010101011111011100111100101100111
    return 0;
}