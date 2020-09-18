#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        if (nums.size() < 2)
            return false;

        bool ret = false;

        size_t num_limit = nums.size() - 1;
        if (k > 0) {
            for (size_t i = 0 ; i < num_limit ; i++) {
                int ac = nums[i];

                for (int ii = i +1 ; ii < nums.size(); ii++) {
                    ac += nums[ii];

                    if (ac % k ==0) {
                        ret = true;
                        ii = nums.size();
                        i = num_limit;
                    }
                }
            }
        } else {
            // find 0 , 0
            int z_c = 0;
            for (int i = 0 ; z_c < 2 && i < nums.size(); i++) {
                if (nums[i] ==0) {
                    z_c++;
                } else {
                    z_c = 0;
                }
            }
            if (z_c >=2) ret = true;
        }
        
        
        return ret;
    }
};

int main()
{
    std::vector<int> data;
    data.emplace_back(23);
    data.emplace_back(2);
    data.emplace_back(4);
    data.emplace_back(6);
    data.emplace_back(7);


    Solution ss;
    printf("%d\n", ss.checkSubarraySum(data, 6));


    return 0;
}