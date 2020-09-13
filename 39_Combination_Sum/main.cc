#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>

// Runtime: 8 ms, faster than 88.70% of C++ online submissions for Combination Sum.
// Memory Usage: 10.9 MB, less than 72.88% of C++ online submissions for Combination Sum.

class Solution {
public:
    void sub_task(const std::vector<int> &candidates,
                  const int remain,
                  const int cnadidatex_idx,
                  std::vector<int> *elements,
                  std::vector<std::vector<int>> * result)  const {
        if (remain == 0) {
            // return as one solution
            result->emplace_back(*elements);
        } else if (remain > 0) {
            for (size_t idx = cnadidatex_idx ; idx < candidates.size(); idx ++) {
                elements->emplace_back(candidates[idx]);

                sub_task(candidates, remain - candidates[idx], idx, elements, result);

                elements->pop_back();
            }
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<int> elements;
        std::vector<std::vector<int>> ret;
        sub_task(candidates, target, 0, &elements, &ret);

        return ret;
    }
};


int main()
{
    std::vector<int> data;
    int target;

    target = 7;
    data.emplace_back(2);
    data.emplace_back(3);
    data.emplace_back(6);
    data.emplace_back(7);

    // target = 8;
    // data.emplace_back(3);
    // data.emplace_back(4);
    // data.emplace_back(5);


    Solution ss;
    std::vector<std::vector<int>> ret = ss.combinationSum(data, target);


    for (size_t i = 0; i < ret.size(); i++) {
        for (size_t vi = 0 ; vi < ret[i].size(); vi++) {
            printf("%d ", ret[i][vi]);
        }
        printf("\n");
    }
 
    return 0;
}