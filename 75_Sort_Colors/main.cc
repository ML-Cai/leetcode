#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <unordered_map>

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
// Memory Usage: 8.4 MB, less than 58.08% of C++ online submissions for Sort Colors.

class Solution {
 public:
    void sortColors(std::vector<int>& nums) {
        size_t v[3] = {0};
        auto iter = nums.begin();

        while (iter != nums.end()) {
            v[*iter]++;
            iter++;
        }

        int *p = (int *)nums.data();
        while (v[0]) {
            *p = 0;
            p++;
            v[0]--;
        }
        while (v[1]) {
            *p = 1;
            p++;
            v[1]--;
        }
        while (v[2]) {
            *p = 2;
            p++;
            v[2]--;
        }

    }
};

int main()
{
    std::vector<int> data;
    data.emplace_back(0);
    data.emplace_back(1);
    data.emplace_back(0);
    data.emplace_back(1);
    data.emplace_back(1);
    data.emplace_back(0);
    data.emplace_back(1);

    Solution ss;
    ss.sortColors(data);

    for (int i = 0 ; i < data.size(); i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}