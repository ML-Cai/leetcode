#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>

// Runtime: 12 ms, faster than 92.17% of C++ online submissions for 3Sum Closest.
// Memory Usage: 9.9 MB, less than 60.59% of C++ online submissions for 3Sum Closest.

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        int min_offset = INT32_MAX;
        int min_sum = INT32_MAX;

        const size_t test_limit =  nums.size() -2;
        for (size_t i = 0 ; i < test_limit; i++) {
            // if (i > 0 && nums[i] == nums[i-1]) continue;
            // if (i > 2 && nums[i] > target) break;

            size_t idx_A = i +1;
            size_t idx_B = nums.size() -1;
            int v = nums[i];

            // -1  2  1  -4
            while (idx_A < idx_B) {
                const int &v_A = nums[idx_A];
                const int &v_B = nums[idx_B];
                const int sum = (v + v_A + v_B);
                int diff = sum - target;

                if (diff == 0) {
                    // printf("min : %d %d %d\n", v, v_A, v_B);
                    return target;
                } else if (diff < 0) {
                    idx_A++;
                } else {
                    idx_B--;
                }

                diff = fabs(diff);
                if (diff < min_offset) {
                    // printf("%d %d %d\n", v, v_A, v_B);
                    min_offset = diff;
                    min_sum = sum;
                }
            }
        }
        return min_sum;
    }
};

int main()
{
    std::vector<int> data;

    // data.emplace_back(-1);
    // data.emplace_back(2);
    // data.emplace_back(1);
    // data.emplace_back(-4);

    // data.emplace_back(-10);
    // data.emplace_back(0);
    // data.emplace_back(-2);
    // data.emplace_back(3);
    // data.emplace_back(-8);
    // data.emplace_back(1);
    // data.emplace_back(-10);
    // data.emplace_back(8);
    // data.emplace_back(-8);
    // data.emplace_back(6);
    // data.emplace_back(-7);
    // data.emplace_back(0);
    // data.emplace_back(-7);
    // data.emplace_back(2);
    // data.emplace_back(2);
    // data.emplace_back(-5);
    // data.emplace_back(-8);
    // data.emplace_back(1);
    // data.emplace_back(-4);
    // data.emplace_back(6);

    data.emplace_back(-55);
    data.emplace_back(-24);
    data.emplace_back(-18);
    data.emplace_back(-11);
    data.emplace_back(-7);
    data.emplace_back(-3);
    data.emplace_back(4);
    data.emplace_back(5);
    data.emplace_back(6);
    data.emplace_back(9);
    data.emplace_back(11);
    data.emplace_back(23);
    data.emplace_back(33);

    Solution ss;

    printf("%d \n", ss.threeSumClosest(data, 0));
    

    return 0;
}