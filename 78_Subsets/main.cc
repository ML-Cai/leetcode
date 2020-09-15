#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
// Memory Usage: 7.2 MB, less than 62.65% of C++ online submissions for Subsets.
// or
// Runtime: 4 ms, faster than 66.16% of C++ online submissions for Subsets.
// Memory Usage: 7.3 MB, less than 48.22% of C++ online submissions for Subsets.
class Solution {
public:
    void sub_task_for_perm_1(const std::vector<int>& nums,
                             std::vector<std::vector<int>> *ret) const {

        auto iter = nums.begin();
        while (iter != nums.end()) {
            ret->emplace_back(std::vector<int>(1));
            std::vector<int> &pad = ret->back();
            pad[0] = *iter;
            iter++;
        }
    }

    void sub_task_for_perm_n(const std::vector<int>& nums,
                             std::vector<std::vector<int>> *ret) const {
        ret->emplace_back(nums);
    }


    void sub_task_rec(const std::vector<int>& nums,
                      const size_t op_idx,
                      const int perm_count,
                      std::vector<int> *pad,
                      std::vector<std::vector<int>> *ret) const {
        if (perm_count == 0) {
            ret->emplace_back(*pad);
        } else  {
            for (size_t i = op_idx ; i < nums.size() ; i++) {
                pad->emplace_back(nums[i]);
                sub_task_rec(nums, i +1, perm_count - 1, pad, ret);
                pad->pop_back();
            }
        }
    }

    void sub_task(const std::vector<int>& nums,
                  const int perm_count,
                  std::vector<std::vector<int>> *ret) const {
        std::vector<int> pad;
        pad.reserve(perm_count);
        sub_task_rec(nums, 0, perm_count , &pad, ret);
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        if (nums.size() == 0) {
            ret.emplace_back(std::vector<int>());
            return ret;
        }

        for (size_t ci = 0 ; ci <= nums.size(); ci++) {
            switch (ci) {
            case 0:
                ret.emplace_back(std::vector<int>());
                break;
            case 1:
                sub_task_for_perm_1(nums, &ret);
                break;
            default:
                if (ci == nums.size()) {
                    sub_task_for_perm_n(nums, &ret);
                } else {
                    sub_task(nums, ci,  &ret);
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
    data.emplace_back(3);
    data.emplace_back(2);
    data.emplace_back(4);
    data.emplace_back(1);

    Solution ss;
    std::vector<std::vector<int>> ret = ss.subsets(data);

    for (int i = 0 ; i < ret.size(); i++) {
        printf("[");
        for (int ii = 0 ; ii < ret[i].size(); ii++) {
            printf("%d ", ret[i][ii]);
        }
        printf("]\n");
    }

 
    return 0;
}