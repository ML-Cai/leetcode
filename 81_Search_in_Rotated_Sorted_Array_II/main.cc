#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
// Runtime: 8 ms, faster than 96.41% of C++ online submissions for Search in Rotated Sorted Array II.
// Memory Usage: 14 MB, less than 64.29% of C++ online submissions for Search in Rotated Sorted Array II.


class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        if (nums.size() == 0) return false;

        int idx_A = 0;
        int idx_B = nums.size() -1;
        int vA = nums[idx_A];
        int vB = nums[idx_B];

        if (vA == target || vB == target) return true;
        // [2,5,6,6,6,6,6,0,0,1,2]

        while ((idx_B - idx_A) > 1) {
            int idx_C = idx_A + (idx_B - idx_A) / 2;
            int vC = nums[idx_C];

            if (vC == target) {
                return true;
            } else {
                if (target > vA && target < vB) {
                    // bin
                    if (target > vC)  {
                        idx_A = idx_C;
                        vA = vC;
                    } else if (target < vC) {
                        idx_B = idx_C;
                        vB = vC;
                    }
                } else {
                    if (vA < target) {
                        idx_A++;
                        vA = nums[idx_A];
                        if (vA == target) return true;
                    } else if (target < vB) {
                        idx_B--;
                        vB = nums[idx_B];
                        if (vB == target) return true;
                    } else {
                        return false;
                    }
                }
            }
        }


        return false;
    }
};


int main()
{
    std::vector<int> data;
    data.emplace_back(2);
    data.emplace_back(5);
    data.emplace_back(6);
    data.emplace_back(0);
    data.emplace_back(0);
    data.emplace_back(1);
    data.emplace_back(2);
    
    
    Solution ss;
    printf("%d\n", ss.search(data, 3));
 
    return 0;
}