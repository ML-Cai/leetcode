#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 4 ms, faster than 96.40% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 11.1 MB, less than 75.69% of C++ online submissions for Search in Rotated Sorted Array.

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int ret = -1;
        if (nums.size() == 1) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }

        size_t idxA = 0;
        size_t idxB = nums.size() -1;
        int vA = nums[idxA];
        int vB = nums[idxB];
        if (vA == target) return idxA;
        if (vB == target) return idxB;

        size_t idx_op = 0;
        size_t idx_ed = 0;

        while ((idxB - idxA) >1) {
            size_t idxC = (idxA + idxB) / 2;
            int vC = nums[idxC];
            if (target == vC) return idxC;

            if (target > vA && target < vB) {
                // bin
                if (target > vC)  {
                    idxA = idxC;
                    vA = vC;
                } else if (target < vC) {
                    idxB = idxC;
                    vB = vC;
                }
            } else {
                // 4,5,6,7,0,1,2
                if (target > vA) {
                    idxA++;
                    vA = nums[idxA];
                    if (vA == target) return idxA;
        
                } else if (target < vB) {
                    idxB--;
                    vB = nums[idxB];
                    if (vB == target) return idxB;
                } else {
                    return -1;
                }
            }
        }

        return -1;

    }
};

int main()
{
    std::vector<int> data;
    data.emplace_back(4);
    data.emplace_back(5);
    data.emplace_back(6);
    data.emplace_back(7);
    data.emplace_back(0);
    data.emplace_back(1);
    data.emplace_back(2);

    // data.emplace_back(0);
    // data.emplace_back(1);
    // data.emplace_back(2);
    // data.emplace_back(4);
    // data.emplace_back(5);
    // data.emplace_back(6);
    // data.emplace_back(7);

    Solution ss;
    // printf("%d\n", ss.search(data, 2));
    // printf("%d\n", ss.search(data, 4));
    // printf("%d\n", ss.search(data, 5));
    // printf("%d\n", ss.search(data, 6));
    // printf("%d\n", ss.search(data, 7));
    // printf("%d\n", ss.search(data, 0));
    printf("%d\n", ss.search(data, 1));
    // printf("%d\n", ss.search(data, 2));

    
    return 0;
}