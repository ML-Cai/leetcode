#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 8 ms, faster than 60.09% of C++ online submissions for Next Permutation.
// Memory Usage: 12.3 MB, less than 20.53% of C++ online submissions for Next Permutation.
// or 
// Runtime: 4 ms, faster than 93.30% of C++ online submissions for Next Permutation.
// Memory Usage: 12 MB, less than 97.55% of C++ online submissions for Next Permutation.

class Solution {
public:
    bool sub_task_nextPermutation(std::vector<int>& nums) const {
        if (nums.size() <= 1) return false;

        size_t idx_k = 0;
        int value_k = -1;
        for (size_t i = 1 ; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                idx_k = i-1;
                value_k = nums[idx_k];
            }
        }

        if (value_k == -1) {
            return false;
        }


        int idx_l = 0;
        for (size_t i = nums.size() -1 ; i > idx_k ; i--) {
            if (value_k < nums[i]) {
                idx_l = i;
                break;
            }
        }

        std::swap(nums[idx_k], nums[idx_l]);

        // reverse
        int c = (nums.size() - (idx_k +1)) / 2;
        size_t ss = idx_k +1;
        size_t se = nums.size() -1;
        while (c > 0) {
            std::swap(nums[ss], nums[se]);
            ss++;
            se--;
            c--;
        }

        return true;
    }

    void sub_task_get_min_permutation(std::vector<int>& nums) const {
        std::sort(nums.begin(), nums.end());
    }

    void nextPermutation(std::vector<int>& nums) {
        bool found = sub_task_nextPermutation(nums);

        if (!found) {
            sub_task_get_min_permutation(nums);
        }
    }
};

// class Solution {
// public:
//     bool sub_task_nextPermutation(std::vector<int>& nums) const {
//         if (nums.size() <= 1) return false;

//         bool found_k = false;
//         size_t idx_k = 0;
//         for (size_t i = 1 ; i < nums.size(); i++) {
//             if (nums[i-1] < nums[i]) {
//                 idx_k = i-1;
//                 found_k = true;
//             }
//         }
//         if (!found_k) {
//             return false;
//         }

//         int idx_l = 0;
//         for (size_t i = idx_k +1 ; i < nums.size(); i++) {
//             if (nums[idx_k] < nums[i]) {
//                 idx_l = i;
//             }
//         }

//         std::swap(nums[idx_k], nums[idx_l]);

//         // reverse
//         int c = (nums.size() - (idx_k +1)) / 2;
//         size_t ss = idx_k +1;
//         size_t se = nums.size() -1;
//         while (c > 0) {
//             std::swap(nums[ss], nums[se]);
//             ss++;
//             se--;
//             c--;
//         }

//         return true;
//     }

//     void sub_task_get_min_permutation(std::vector<int>& nums) const {
//         std::sort(nums.begin(), nums.end());
//     }

//     void nextPermutation(std::vector<int>& nums) {
//         bool found = sub_task_nextPermutation(nums);

//         if (!found) {
//             sub_task_get_min_permutation(nums);
//         }
//     }
// };

int main()
{
    std::vector<int> data;
    data.emplace_back(1);
    data.emplace_back(3);
    data.emplace_back(2);
    

    Solution ss;
    ss.nextPermutation(data);

    for (size_t i = 0; i < data.size(); i++) {
        printf("%d ", data[i]);
    }
 
    return 0;
}