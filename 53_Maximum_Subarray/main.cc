#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 4 ms, faster than 99.92% of C++ online submissions for Maximum Subarray.
// Memory Usage: 13.2 MB, less than 72.39% of C++ online submissions for Maximum Subarray.

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {

        int64_t max_sum = INT64_MIN;
        int64_t sum = 0;
        for (size_t i = 0 ; i < nums.size() ; i++) {
            if (sum < 0 && nums[i] > sum) {
                sum = nums[i];
            } else {
                sum += nums[i];
                
            }
            if (max_sum < sum) max_sum = sum;
        }
        
        return (int)max_sum;
    }
};

int main()
{
    std::vector<int> data;
    data.emplace_back(-2);
    data.emplace_back(1);
    data.emplace_back(-3);
    data.emplace_back(4);
    data.emplace_back(-1);
    data.emplace_back(2);
    data.emplace_back(1);
    data.emplace_back(-5);
    data.emplace_back(4);

    Solution ss;
    printf("%d\n", ss.maxSubArray(data));

    return 0;
}