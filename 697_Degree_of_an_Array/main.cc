#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>
class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        //nums.length will be between 1 and 50,000.
        //nums[i] will be an integer between 0 and 49,999.   
        
        std::unordered_map<int, std::tuple<int, int, int> > map_num_to_pos;     // [num as key, <freq, first pos, lastpos>]
        int max_freq = 1;
        int max_freq_key = nums[0];
        int min_pos_len = 0;
        map_num_to_pos.emplace(nums[0], std::tuple<int, int, int> (1, 0, 0));
        
        for (size_t i = 1 ; i < nums.size(); i++) {
            auto iter = map_num_to_pos.find(nums[i]);
            
            if(iter != map_num_to_pos.end()) {
                std::get<0>(iter->second) ++;   // add freq
                std::get<2>(iter->second) = i;  // update last pos
            } else {
                auto fed = map_num_to_pos.emplace(nums[i], std::tuple<int, int, int> (1, i, i));
                iter = fed.first;
            }
            
            const std::tuple<int, int, int> &cur_data = iter->second;
            bool update =false;
            if (std::get<0>(cur_data) > max_freq) {
                update = true;
            } else if (std::get<0>(cur_data) == max_freq) {
                int pos_len = std::get<2>(cur_data) - std::get<1>(cur_data);
                if (pos_len < min_pos_len) {       
                    update = true;
                }
            }
            
            if (update) {
                max_freq = std::get<0>(cur_data);
                max_freq_key = nums[i];
                min_pos_len = std::get<2>(cur_data) - std::get<1>(cur_data);
            }
        }
        
        return min_pos_len+1;
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
    printf("%d\n", ss.findShortestSubArray(data));


    return 0;
}