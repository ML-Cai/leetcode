#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 48 ms, faster than 65.87% of C++ online submissions for Merge Intervals.
// Memory Usage: 14.3 MB, less than 80.46% of C++ online submissions for Merge Intervals.
// or
// Runtime: 36 ms, faster than 93.54% of C++ online submissions for Merge Intervals.
// Memory Usage: 14.1 MB, less than 99.79% of C++ online submissions for Merge Intervals.

class Solution {
public:

    bool isOverlap (const std::vector<int> &A,
                    const std::vector<int> &B,
                    std::pair<int, int> *overlap) const {
        bool ret = false;

        int min, max;
        if (A[0] <= B[0]) {
            min = A[0];
        } else {
            if (A[1] <= B[0]) {
                min = A[1];
            } else {
                min = B[0];
            }
        }

        if (A[1] >= B[1]) {
            max = A[1];
        } else {
            max = B[1];
        }

        int len_A = A[1] - A[0];
        int len_B = B[1] - B[0];
        int len_C = max - min;
        if ((len_A + len_B) >= len_C) {
            ret = true;
            overlap->first = min;
            overlap->second = max;
        }
        return ret;
    }

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        // [[1,3],[2,6],[8,10],[15,18]]
        // [[2,6], [1,3],[8,10],[15,18]]
        if (intervals.size() <= 1) {
            return intervals;
        }

        size_t last_valid_idx = intervals.size() - 1;

        for (int i = 0 ; i <= last_valid_idx ; i++) {
            std::vector<int> & interval_A = intervals[i];
            size_t cur_valid_idx = last_valid_idx;

            for (int j = i + 1 ; j <= last_valid_idx ; j++) {
                std::vector<int> & interval_B = intervals[j];
                std::pair<int, int> overlap;
                bool ov = isOverlap(interval_A, interval_B, &overlap);
                if (ov) {
                    // swap last valid to B,
                    std::vector<int> & interval_last = intervals[last_valid_idx];
                    interval_B[0] = interval_last[0];
                    interval_B[1] = interval_last[1];
                    interval_A[0] = overlap.first;
                    interval_A[1] = overlap.second;
                    last_valid_idx--;
                }
            }

            if (cur_valid_idx != last_valid_idx) {
                i--;
            }
        }
        // printf("last_valid_idx %d\n", last_valid_idx);

        if (last_valid_idx != (intervals.size() - 1)) {
            intervals.erase(intervals.begin() + last_valid_idx +1,
                            intervals.end());
        }
        return intervals;
    }
};

void add_slice(int left, int right,  std::vector<std::vector<int>> *data) {
    std::vector<int> a;
    a.emplace_back(left);
    a.emplace_back(right);
    data->emplace_back(a);
}

int main()
{
    std::vector<std::vector<int>> data;
    add_slice(1, 3, &data);
    add_slice(2, 6, &data);
    add_slice(8, 10, &data);
    add_slice(15, 18, &data);
    add_slice(1, 4, &data);
    add_slice(4, 5, &data);

    // add_slice(1, 4, &data);
    // add_slice(0, 2, &data);
    // add_slice(3, 5, &data);

    Solution ss;
    std::vector<std::vector<int>> ret = ss.merge(data);

    for (int i = 0 ; i < ret.size(); i++) {
        printf("%d %d\n", ret[i][0], ret[i][1]);
    }

 
    return 0;
}