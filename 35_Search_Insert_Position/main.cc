#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// would be 4ms , 8ms ,12ms, 16ms, 24ms ....
// Runtime: 4 ms, faster than 99.39% of C++ online submissions for Search Insert Position.
// Memory Usage: 9.9 MB, less than 16.10% of C++ online submissions for Search Insert Position.

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        size_t idx_A = 0;
        size_t idx_B = nums.size() -1;

        // 0   1   2   3
        // 1   3   5   7
        while (idx_A <= idx_B) {
            const size_t idx_next = idx_A + ((idx_B - idx_A) >>1);

            if (nums[idx_next] < target) {
                idx_A = idx_next + 1;
            } else {
                if (!idx_next) break;
                idx_B = idx_next -1;
            }
        }

        return idx_A;
    }
};

int main()
{
    std::vector<int> data;
    data.emplace_back(1);
    // data.emplace_back(3);
    // data.emplace_back(5);
    // data.emplace_back(6);

    Solution ss;
    printf("%d\n", ss.searchInsert(data, 1));
    printf("%d\n", ss.searchInsert(data, 5));
    printf("%d\n", ss.searchInsert(data, 2));
    printf("%d\n", ss.searchInsert(data, 7));
    printf("%d\n", ss.searchInsert(data, 0));

 
    return 0;
}