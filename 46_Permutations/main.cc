#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutations.
// Memory Usage: 7.8 MB, less than 63.29% of C++ online submissions for Permutations.
// 
//  or
// 
// Runtime: 4 ms, faster than 87.96% of C++ online submissions for Permutations.
// Memory Usage: 7.5 MB, less than 88.22% of C++ online submissions for Permutations.

class Solution {
public:

    void sub_task(std::vector<int>& nums,
                  const size_t ed_idx,
                  std::vector<int> *pad,
                  std::vector<std::vector<int>> *result) const {
        if (ed_idx == -1) {
            result->emplace_back(*pad);
        } else {
            for (size_t i = 0 ; i <= ed_idx; i++) {
                pad->emplace_back(nums[i]);

                // int t = nums[i];
                // nums[i] = nums[ed_idx];
                // nums[ed_idx] = t;
                std::swap(nums[i], nums[ed_idx]);

                sub_task(nums, ed_idx - 1, pad, result);

                pad->pop_back();

                // t = nums[i];
                // nums[i] = nums[ed_idx];
                // nums[ed_idx] = t;
                std::swap(nums[i], nums[ed_idx]);
            }
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        std::vector<int> pad;
        pad.reserve(nums.size());
        sub_task(nums, nums.size() -1, &pad, &ret);

        return ret;
    }
};

int main()
{
    std::vector<int> data;
    data.emplace_back(1);
    data.emplace_back(2);
    data.emplace_back(3);

    Solution ss;
    std::vector<std::vector<int>> ret = ss.permute(data);


    for (size_t i = 0; i < ret.size(); i++) {
        for (size_t vi = 0 ; vi < ret[i].size(); vi++) {
            printf("%d ", ret[i][vi]);
        }
        printf("\n");
    }
 
    return 0;
}