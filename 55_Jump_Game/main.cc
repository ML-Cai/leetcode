#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 20 ms, faster than 82.49% of C++ online submissions for Jump Game.
// Memory Usage: 12.9 MB, less than 76.81% of C++ online submissions for Jump Game.
// or
// Runtime: 16 ms, faster than 96.50% of C++ online submissions for Jump Game.
// Memory Usage: 13 MB, less than 50.85% of C++ online submissions for Jump Game.

// class Solution {
// public:
//     bool canJump(std::vector<int>& nums) {
//         // 3,2,1,0,4
//         int last_zero_step = -1;
//         if (nums.size() <= 1) return true;

//         for (int step_i = nums.size() -1 ; step_i >=0; step_i--) {
//             int cur_step = nums[step_i];

//             if (cur_step == 0) {
//                 if (last_zero_step == -1) {
//                     last_zero_step = step_i;
//                 }
//             } else if (last_zero_step != -1) {
//                 int offset = last_zero_step - step_i;
//                 if (cur_step > offset) {
//                     last_zero_step = -1;
//                 } else if (cur_step == offset && last_zero_step == nums.size() -1) {
//                     last_zero_step = -1;
//                 }
//             }
//         }

//         return last_zero_step == -1;
//     }
// };


class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        // 3,2,1,0,4
        int prev_max_step = -1;
        if (nums.size() <= 1) return true;

        auto iter = nums.begin();
        while (iter != nums.end()) {
            int cur_step = *iter;

            if (prev_max_step < cur_step) {
                prev_max_step = cur_step;
            }
            prev_max_step--;
            if (prev_max_step < 0) {
                break;
            }
            iter++;
        }

        if (prev_max_step < 0 && iter != (nums.begin() + nums.size() - 1)) {
            return false;
        }

        return true;
    }
};


int main()
{
    std::vector<int> data;
    data.emplace_back(3);
    data.emplace_back(2);
    data.emplace_back(1);
    data.emplace_back(0);
    data.emplace_back(4);

    // data.emplace_back(2);
    // data.emplace_back(0);
    // data.emplace_back(0);
    // data.emplace_back(0);
    Solution ss;
    printf("%d\n", ss.canJump(data));

 
    return 0;
}