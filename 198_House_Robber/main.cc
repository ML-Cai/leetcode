#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <unordered_map>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        /*
          2,    7,    9,    3,    1
                      ^           
                      
          1,    1,    1,    9,    1,
                      ^     ^
                     {2,   {10,
                      1}    1 or 2}
                      
                      [i] 
                       {do : [i-2] + [i]
                        not to do : [i-1]}
        */
        if (nums.size() == 0)
            return 0;
        else if (nums.size() ==1)
            return nums[0];
        
        std::vector<int> mm (nums.size(), 0);
        
        // init
        mm[0] = nums[0];
        mm[1] = std::max(nums[1] + 0,   // do
                         nums[0]);      // not to do
        
        for (size_t i = 2 ; i < nums.size(); i++) {
            mm[i] = std::max(mm[i - 2] + nums[i],     // do
                             mm[i - 1]);              // no to do
        }
        
        return mm.back();
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
