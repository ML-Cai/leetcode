#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;

        std::sort(nums.begin(), nums.end());

        //       -1   0   1   -1   0   1
        //== >   -1  -1   0    0   1   1
        for (size_t ni = 0 ; ni < nums.size(); ni++) {
            if (nums[ni] > 0) {   // only check the num which is less and equal than 0
                break;
            }

            if (ni != 0) {
                if (nums[ni] == nums[ni-1]) {   // skip same value tested at last step.
                    continue;
                }
            }

            const int v = nums[ni];
            size_t bound_A = ni +1;
            size_t bound_B = nums.size() -1;

            while (bound_A < bound_B) {
                const int vA = nums[bound_A];
                const int vB = nums[bound_B];
                if (vB <0) break;   // if left bound less than 0, skip all

                const int sum = v + vA + vB;

                if (sum == 0) {
                    ret.emplace_back(std::vector<int>(3));
                    ret.back()[0] = v;
                    ret.back()[1] = vA;
                    ret.back()[2] = vB;

                    // find next possible search location

                    while ((bound_A < bound_B) && (vA == nums[bound_A])) {
                        bound_A++;
                    }
                    while ((bound_A < bound_B) && (vB == nums[bound_B])) {
                        bound_B--;
                    }

                } else if (sum < 0) {
                    bound_A++;
                } else {
                    bound_B--;
                }
            }
        }

        return ret;
    }
};

int main()
{
    std::vector<int> data;

    data.emplace_back(-1);
    data.emplace_back(0);
    data.emplace_back(1);
    data.emplace_back(2);
    data.emplace_back(-1);
    data.emplace_back(0);
    data.emplace_back(-1);
    data.emplace_back(-1);
    data.emplace_back(0);
    data.emplace_back(-4);
    // data.emplace_back(-1);
    // data.emplace_back(0);
    // data.emplace_back(1);
    // data.emplace_back(-1);
    // data.emplace_back(0);
    // data.emplace_back(1);
    
    Solution ss;

    std::vector<std::vector<int>> output = ss.threeSum(data);
    for (int i = 0 ; i < output.size() ; i++) {
        for (int j = 0 ; j < output[i].size() ; j++) {
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }

    return 0;
}