#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 12 ms, faster than 59.87% of C++ online submissions for Permutations II.
// Memory Usage: 9.6 MB, less than 27.89% of C++ online submissions for Permutations II.
// or
// Runtime: 8 ms, faster than 84.44% of C++ online submissions for Permutations II.
// Memory Usage: 9.5 MB, less than 34.18% of C++ online submissions for Permutations II.

class Solution {
public:

    void sub_task(const size_t ed_idx,
                  std::vector<int> *nums,
                  std::vector<int> *pad,
                  std::vector<std::vector<int>> *result) const {
        if (ed_idx == -1) {
            // result->emplace_back(*pad);
            result->emplace_back(*nums);
        } else {
            std::unordered_set<int> seen;
            int *p = nums->data();
            int *p_ed_idx = p + ed_idx;

            for (size_t i = 0 ; i <= ed_idx ; i++) {
                int *p_i = p +i;
                int v = *p_i;

                if (seen.find(v) == seen.end()) {
                    seen.emplace(v);
                    // pad->emplace_back((*nums)[i]);

                    // std::swap((*nums)[i], (*nums)[ed_idx]);
                    int t = *p_ed_idx;
                    *p_ed_idx = v;
                    *p_i = t;

                    this->sub_task(ed_idx -1, nums, pad, result);

                    // std::swap((*nums)[i], (*nums)[ed_idx]);
                    t = *p_ed_idx;
                    *p_ed_idx = *p_i;
                    *p_i = t;

                    // pad->pop_back();
                }
            }
            // for (size_t i = 0 ; i <= ed_idx ; i++) {
            //     if (seen.find((*nums)[i]) == seen.end()) {
            //         seen.emplace((*nums)[i]);
            //         // pad->emplace_back((*nums)[i]);

            //         std::swap((*nums)[i], (*nums)[ed_idx]);

            //         this->sub_task(ed_idx -1, nums, pad, result);

            //         std::swap((*nums)[i], (*nums)[ed_idx]);

            //         // pad->pop_back();
            //     }
            // }
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<int> pad;
        std::vector<std::vector<int>> ret;
        pad.reserve(nums.size());

        sub_task(nums.size() -1, &nums, &pad, &ret);

        return ret;
    }
};

int main()
{
    std::vector<int> data;
    data.emplace_back(1);
    data.emplace_back(1);
    data.emplace_back(2);

    Solution ss;
    std::vector<std::vector<int>> ret = ss.permuteUnique(data);


    for (size_t i = 0; i < ret.size(); i++) {
        for (size_t vi = 0 ; vi < ret[i].size(); vi++) {
            printf("%d ", ret[i][vi]);
        }
        printf("\n");
    }
 
    return 0;
}