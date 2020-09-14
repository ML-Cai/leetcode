#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

// Runtime: 32 ms, faster than 85.24% of C++ online submissions for 4Sum.
// Memory Usage: 13.1 MB, less than 76.67% of C++ online submissions for 4Sum.

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> ret;
        if (nums.size() < 4) return ret;


        std::sort(nums.begin(), nums.end());

        const size_t ref_limit = nums.size() - 3;
        int prev_ref = nums[0] -1;  // assume datarange wouldn't overflow
        for (size_t refi = 0; refi < ref_limit ; refi++) {
            const int &ref = nums[refi];
            if (ref == prev_ref) {
                continue;
            } else if (ref > 0 && (ref - target) > 0) {
                break;
            }

            prev_ref = ref;

            const size_t v_limit = nums.size() - 2;
            int prev_v = nums[refi +1] -1;
            int new_target = -(-target + nums[refi]);

            for (size_t vi = refi +1 ; vi < v_limit; vi++) {
                const int &v = nums[vi];
                if (v == prev_v) {
                    continue;
                } else if (v > 0 && (v - new_target) > 0) {
                    break;
                }  else if (v > 0 && (v - new_target) > 0) {
                    continue;
                }
                prev_v = v;

                size_t idx_A = vi +1;
                size_t idx_B = nums.size() - 1;

                while (idx_A < idx_B) {
                    const int &v_A = nums[idx_A];
                    const int &v_B = nums[idx_B];
                    int sum = v + v_A + v_B;

                    if (sum == new_target) {
                        ret.emplace_back(std::vector<int>(4));
                        std::vector<int> & tmp = ret.back();
                        tmp[0] = ref;
                        tmp[1] = v;
                        tmp[2] = v_A;
                        tmp[3] = v_B;

                        while (idx_A < idx_B && nums[idx_A] == v_A) {
                            idx_A++;
                        }

                        while (idx_A < idx_B && nums[idx_B] == v_B) {
                            idx_B--;
                        }
                    } else if (sum < new_target) {
                        idx_A++;
                    } else {
                        idx_B--;
                    }
                }
            }
        }

        return ret;
    }
};

int main()
{
    std::vector<int> data;
    int target;
    
    // target = 0;
    // data.emplace_back(1);
    // data.emplace_back(0);
    // data.emplace_back(-1);
    // data.emplace_back(0);
    // data.emplace_back(-2);
    // data.emplace_back(2);

    // target = 2;
    // data.emplace_back(2);
    // data.emplace_back(1);
    // data.emplace_back(0);
    // data.emplace_back(-1);

    target = 0;
    data.emplace_back(-3);
    data.emplace_back(-2);
    data.emplace_back(-1);
    data.emplace_back(0);
    data.emplace_back(0);
    data.emplace_back(1);
    data.emplace_back(2);
    data.emplace_back(3);

    Solution ss;

    std::vector<std::vector<int>> output = ss.fourSum(data, target);
    for (int i = 0 ; i < output.size() ; i++) {
        for (int j = 0 ; j < output[i].size() ; j++) {
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }

    return 0;
}