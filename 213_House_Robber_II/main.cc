#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <unordered_map>

// use variable replace n vector
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         if (nums.size() == 0)
//             return 0;
//         else if (nums.size() == 1)
//             return nums[0];
//         /*
//            P[i] = max (P[i-2] + n[i],  P[i-1])
//         */
        
//         int profit_no_0[2];
//         int profit_no_n[2];
        
//         profit_no_0[0] = 0;
//         profit_no_0[1] = nums[1];
        
//         profit_no_n[0] = nums[0];
//         profit_no_n[1] = std::max(nums[1], profit_no_n[0]);
        
//         const size_t last_idx = nums.size() -1;
//         for (int i = 2 ; i < last_idx ; i++) {
//             int vi_no_0 = std::max(profit_no_0[0] + nums[i], profit_no_0[1]);
//             int vi_no_n = std::max(profit_no_n[0] + nums[i], profit_no_n[1]);
            
//             profit_no_0[0] = profit_no_0[1];
//             profit_no_0[1] = vi_no_0;
            
//             profit_no_n[0] = profit_no_n[1];
//             profit_no_n[1] = vi_no_n;
//         }
        
//         if (nums.size() > 2) {
//             // profit_no_n doesn't consider n value, so just update profit_no_0
//             profit_no_0[1] = std::max(profit_no_0[0] + nums[last_idx], profit_no_0[1]);
//         }
        
//         return std::max(profit_no_0[1], profit_no_n[1]);
//     }
// };




class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        /*
        
           P[i] = max (P[i-2] + n[i],  P[i-1])
        */
        
        std::vector<int> profit_no_0(nums.size(), 0);
        std::vector<int> profit_no_n(nums.size(), 0);
        
        profit_no_0[0] = 0;
        profit_no_0[1] = nums[1];
        
        profit_no_n[0] = nums[0];
        profit_no_n[1] = std::max(nums[1], profit_no_n[0]);
        
        for (int i = 2 ; i < (nums.size() -1) ; i++) {
            profit_no_0[i] = std::max(profit_no_0[i -2] + nums[i], profit_no_0[i-1]);
            profit_no_n[i] = std::max(profit_no_n[i -2] + nums[i], profit_no_n[i-1]);
        }
        
        if (nums.size() > 2) {
            size_t last_idx = nums.size() -1;
            profit_no_0[last_idx] = std::max(profit_no_0[last_idx -2] + nums[last_idx], profit_no_0[last_idx-1]);
            profit_no_n[last_idx] = profit_no_n[last_idx -1];
        }
        
        return std::max(profit_no_0.back(), profit_no_n.back());
    }
};

int main()
{
    std::vector<int> data;
    data.emplace_back(7);
    data.emplace_back(1);
    data.emplace_back(5);
    data.emplace_back(3);
    data.emplace_back(6);
    data.emplace_back(4);

    Solution ss;
    printf("%d\n ", ss.rob(data));

    return 0;
}
