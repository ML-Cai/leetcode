#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>

// Runtime: 8 ms, faster than 99.70% of C++ online submissions for Combinations.
// Memory Usage: 9 MB, less than 81.33% of C++ online submissions for Combinations.


class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> ret;
        int level = 0;
        std::vector<int> level_value(k, 0);

        while (level >= 0) {
            int remain = n - level_value[level];
            level_value[level]++;

            if ((level + remain) < k) {     // skip test in remain less than required
                level--;
            } else if (level_value[level] > n) {
                level--;
            } else if (level == (k-1)) {
                ret.emplace_back(level_value);
            } else {
                level_value[level + 1] = level_value[level];
                level++;
            }
        }
        return ret;
    }
};

int main()
{
    std::vector<int> data;
    int target;

    Solution ss;
    // std::vector<std::vector<int>> ret = ss.combine(4, 2);
    std::vector<std::vector<int>> ret = ss.combine(1, 1);


    for (size_t i = 0; i < ret.size(); i++) {
        for (size_t vi = 0 ; vi < ret[i].size(); vi++) {
            printf("%d ", ret[i][vi]);
        }
        printf("\n");
    }
 
    return 0;
}