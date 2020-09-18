#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
// Runtime: 4 ms, faster than 99.30% of C++ online submissions for Remove Duplicates from Sorted Array II.
// Memory Usage: 11 MB, less than 64.23% of C++ online submissions for Remove Duplicates from Sorted

// class Solution {
// public:
//     int removeDuplicates(std::vector<int>& nums) {
//         if (nums.size() == 0) {
//             return 0;
//         } else if (nums.size() == 1) {
//             return 1;
//         }

//         // [1,1,1,2,2,3]

//         int count = 1;
//         int prev_v = nums[0];
//         size_t stored_idx = 1;

//         auto iter = nums.begin() +1;
//         while (iter != nums.end()) {
//             const int &v = *iter;
//             iter++;

//             if (prev_v == v) {
//                 count++;
//             } else {
//                 count = 1;
//             }

//             if (count <= 2) {
//                 nums[stored_idx] = v;
//                 stored_idx++;
//             }
//             prev_v = v;
//         }

//         // nums.erase(nums.begin() + stored_idx, nums.end());
//         // return nums.size();
//         return stored_idx;
//     }
// };

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        // [1,1,1,2,2,3]
        size_t stored_idx = 2;
        auto iter = nums.begin() + stored_idx;
        while (iter != nums.end()) {
            if (*iter != nums[stored_idx -2]) {
                nums[stored_idx] = *iter;
                stored_idx++;
            }
            iter++;
        }

        return stored_idx;
    }
};


int main()
{
    std::vector<int> data;
    data.emplace_back(0);
    data.emplace_back(0);
    data.emplace_back(1);
    data.emplace_back(1);
    data.emplace_back(1);
    data.emplace_back(1);
    data.emplace_back(2);
    data.emplace_back(3);
    data.emplace_back(3);

    Solution ss;
    printf("%d\n", ss.removeDuplicates(data));
 
    return 0;
}