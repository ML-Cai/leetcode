#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Success
// Details 
// Runtime: 12 ms, faster than 96.53% of C++ online submissions for Two Sum.
// Memory Usage: 10.2 MB, less than 33.63% of C++ online submissions for Two Sum.
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::unordered_map<int, int> hash;
        std::vector<int> ret;
        for (size_t i = 0 ; i < nums.size() ; i++) {
            int desired = target - nums[i];

            std::unordered_map<int, int>::iterator iter = hash.find(desired);
            if (iter != hash.end()) {
                ret.emplace_back(iter->second);
                ret.emplace_back(i);
                return ret;
            }
            hash.emplace(nums[i], i);
        }
        return ret;
    }
};

int main()
{
    std::vector<int> data;
    int target;
    
    // target = 9;
    // data.emplace_back(2);
    // data.emplace_back(7);
    // data.emplace_back(11);
    // data.emplace_back(15);

    // target = 6;
    // data.emplace_back(3);
    // data.emplace_back(2);
    // data.emplace_back(4);
    
    target = 6;
    data.emplace_back(3);
    data.emplace_back(3);
    

    Solution solution;

    std::vector<int> output = solution.twoSum(data, target);
    printf("output %d %d", output[0], output[1]);

    return 0;
}