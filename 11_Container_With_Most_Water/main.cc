#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 28 ms, faster than 93.62% of C++ online submissions for Container With Most Water.
// Memory Usage: 14.2 MB, less than 94.30% of C++ online submissions for Container With Most Water.

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        size_t idxL = 0;
        size_t idxR = height.size() - 1;

        int max_area = 0;
        while (idxL != idxR) {
            size_t area = (idxR - idxL) * std::min(height[idxL], height[idxR]);

            if (max_area < area) {
                max_area = area;
            }

            if (height[idxL] < height[idxR]) {
                idxL++;
            } else {
                idxR--;
            }
        }

        return max_area;
    }
};

int main()
{
    Solution ss;

    std::vector<int> data;
    data.emplace_back(1);
    data.emplace_back(8);
    data.emplace_back(6);
    data.emplace_back(2);
    data.emplace_back(5);
    data.emplace_back(4);
    data.emplace_back(8);
    data.emplace_back(3);
    data.emplace_back(7);
    // ,8,6,2,5,4,8,3,7);

    printf("%d\n", ss.maxArea(data));
    return 0;
}