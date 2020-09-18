#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool divisorGame(int N) {
        return N %2 ==0;
    }
};

int main()
{
    Solution ss;
    printf("%d\n", ss.divisorGame(1));
    printf("%d\n", ss.divisorGame(2));
    printf("%d\n", ss.divisorGame(3));
    printf("%d\n", ss.divisorGame(4));
    printf("%d\n", ss.divisorGame(5));
    printf("%d\n", ss.divisorGame(6));
    printf("%d\n", ss.divisorGame(7));
    printf("%d\n", ss.divisorGame(8));
    printf("%d\n", ss.divisorGame(9));
    printf("%d\n", ss.divisorGame(10));
    return 0;
}