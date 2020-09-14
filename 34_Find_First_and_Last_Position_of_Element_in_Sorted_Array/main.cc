#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 8 ms, faster than 99.95% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 13.9 MB, less than 34.64% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

class Solution {
public:
    struct task_page {
        task_page(size_t idx_A, size_t idx_B, int vA, int vB) {
            this->idx_A = idx_A;
            this->idx_B = idx_B;
            this->vA = vA;
            this->vB = vB;
        }
        size_t idx_A;
        size_t idx_B;
        int vA;
        int vB;
    };

    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> ret(2);
        ret[0] = -1;
        ret[1] = -1;

        if (nums.size() == 0) return ret;
        if (nums.size() == 1 && nums[0] != target) {
            return ret;
        }

        ret[0] = nums.size()-1;
        ret[1] = 0;

        std::vector<task_page> task_list;
        task_list.emplace_back(task_page(0, nums.size() -1, nums[0], nums[nums.size() -1]));

        while (task_list.size() > 0) {
            const task_page task = task_list.back();
            task_list.pop_back();

            if (task.vA == target && task.vB == target) {
                if (ret[0] > task.idx_A) ret[0] = task.idx_A;
                if (ret[1] < task.idx_A) ret[1] = task.idx_A;
                if (ret[0] > task.idx_B) ret[0] = task.idx_B;
                if (ret[1] < task.idx_B) ret[1] = task.idx_B;
            } else if ((task.idx_B - task.idx_A) <= 1) {
                if (task.vA == target) {
                    if (ret[0] > task.idx_A) ret[0] = task.idx_A;
                    if (ret[1] < task.idx_A) ret[1] = task.idx_A;
                }
                if (task.vB == target) {
                    if (ret[0] > task.idx_B) ret[0] = task.idx_B;
                    if (ret[1] < task.idx_B) ret[1] = task.idx_B;
                }
            } else if (task.vA <= target && task.vB >= target) {
                size_t idx_C = (task.idx_A + task.idx_B) /2;
                int vC = nums[idx_C];

                if (vC >= target) {
                    task_list.emplace_back(task_page(task.idx_A,
                                                     idx_C,
                                                     task.vA,
                                                     vC));
                }

                if (vC <= target) {
                    task_list.emplace_back(task_page(idx_C,
                                                     task.idx_B,
                                                     vC,
                                                     task.vB));

                }
            }
        }

        if (nums[ret[0]] != target) ret[0] = -1;
        if (nums[ret[1]] != target) ret[1] = -1;

        return ret;
    }
};

int main()
{
    std::vector<int> data;
    data.emplace_back(5);
    data.emplace_back(7);
    // data.emplace_back(7);
    // data.emplace_back(8);
    // data.emplace_back(8);
    // data.emplace_back(8);
    // data.emplace_back(8);
    // data.emplace_back(10);


    Solution ss;
    std::vector<int> ret = ss.searchRange(data, 8);

    for (int i = 0 ; i < ret.size(); i++) {
        printf("%d\n", ret[i]);
    }
    
    return 0;
}