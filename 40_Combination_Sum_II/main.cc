#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 8 ms, faster than 88.54% of C++ online submissions for Combination Sum II.
// Memory Usage: 10.6 MB, less than 89.36% of C++ online submissions for Combination Sum II.

class Solution {
public:

    void sub_task(const std::vector<int> &candidates,
                  size_t idx_op,
                  int target,
                  int sum,
                  std::vector<int> *pad,
                  std::vector<std::vector<int>> *result) const {

        if (sum == target) {
            result->emplace_back(*pad);
        } else if (sum < target) {

            for (size_t i = idx_op ; i < candidates.size() ; i++) {
                if (i != idx_op && candidates[i] == candidates[i - 1]) continue;

                pad->emplace_back(candidates[i]);

                this->sub_task(candidates, i +1, target, sum + candidates[i], pad, result);

                pad->pop_back();
            }

        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<int> pad;
        std::vector<std::vector<int>> result;
        std::sort(candidates.begin(), candidates.end());
        sub_task(candidates, 0, target, 0, &pad, &result);
        
        return result;
    }
};


int main()
{
    std::vector<int> data;
    int target;

    target = 8;
    data.emplace_back(10);
    data.emplace_back(1);
    data.emplace_back(2);
    data.emplace_back(7);
    data.emplace_back(6);
    data.emplace_back(1);
    data.emplace_back(5);

    // target = 8;
    // data.emplace_back(3);
    // data.emplace_back(4);
    // data.emplace_back(5);


    Solution ss;
    std::vector<std::vector<int>> ret = ss.combinationSum2(data, target);


    for (size_t i = 0; i < ret.size(); i++) {
        for (size_t vi = 0 ; vi < ret[i].size(); vi++) {
            printf("%d ", ret[i][vi]);
        }
        printf("\n");
    }
 
    return 0;
}