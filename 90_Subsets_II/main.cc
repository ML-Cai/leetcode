#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 4 ms, faster than 84.39% of C++ online submissions for Subsets II.
// Memory Usage: 7.6 MB, less than 91.37% of C++ online submissions for Subsets II.

class Solution {
public:

    void sub_task_1(const std::vector<int>& nums,
                    std::vector<std::vector<int>> * ret) const {
        ret->reserve(ret->size() + nums.size());

        auto iter = nums.begin();
        do {
            const int v = *iter;
            std::vector<int> subset(1, v);
            ret->emplace_back(subset);

            iter++;
            while (iter != nums.end() && *iter == v) iter++;
        } while (iter != nums.end());
    }


    void sub_sub_task_n(const std::vector<int>& nums,
                        const size_t op_idx,
                        const size_t set_count,
                        std::vector<int> *pad,
                        std::vector<std::vector<int>> * ret) const {
        if (pad->size() == set_count) {
            ret->emplace_back(*pad);
        } else {
            size_t i = op_idx;
            while (i < nums.size()) {
                const int v = nums[i];
                pad->emplace_back(v);
                sub_sub_task_n(nums, i + 1, set_count, pad, ret);
                pad->pop_back();

                while (i < nums.size() && v == nums[i]) {
                    i++;
                }
            }
        }
    }

    void sub_task_n(const std::vector<int>& nums,
                    const size_t set_count,
                    std::vector<std::vector<int>> * ret) const {
        std::vector<int> pad;
        pad.reserve(nums.size());
        sub_sub_task_n(nums, 0, set_count, &pad, ret);
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;

        

        std::sort(nums.begin(), nums.end());

        for (size_t set_count = 0 ; set_count <= nums.size(); set_count++) {
            switch (set_count) {
            case 0:
                ret.emplace_back(std::vector<int>());
                break;
            case 1:
                sub_task_1(nums, &ret);
                break;
            default:
                if (set_count == nums.size()) {
                    ret.emplace_back(nums);
                } else {
                    sub_task_n(nums, set_count, &ret);
                }
                break;
            }
        }

        return ret;
    }
};



int main()
{
    std::vector<int> data;
    data.emplace_back(0);
    // data.emplace_back(1);
    // data.emplace_back(2);
    // data.emplace_back(2);

    Solution ss;
    std::vector<std::vector<int>> ret = ss.subsetsWithDup(data);

    for (int i = 0 ; i < ret.size(); i++) {
        printf("[");
        for (int ii = 0 ; ii < ret[i].size(); ii++) {
            printf("%d ", ret[i][ii]);
        }
        printf("]\n");
    }

 
    return 0;
}