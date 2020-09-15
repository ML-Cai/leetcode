#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 36 ms, faster than 47.17% of C++ online submissions for Insert Interval.
// Memory Usage: 17.2 MB, less than 41.87% of C++ online submissions for Insert Interval.
class Solution {
public:

    bool isOverlap(const std::vector<int> &intA,
                   const std::vector<int> &intB,
                   std::pair<int, int> * overlap) const {
        // [1,2],[3,5],[6,7],[8,10],[12,16]
        // [3,5],[1,7],[8,10],[12,16]
        int min, max;

        if (intA[0] <= intB[0]) {
            min = intA[0];
        } else {
            min = intB[0];
        }

        if (intA[1] <= intB[1]) {
            max = intB[1];
        } else {
            max = intA[1];
        }

        int len_A = intA[1] - intA[0];
        int len_B = intB[1] - intB[0];
        int len_max = max - min;

        if ((len_A + len_B) >= len_max) {
            overlap->first = min;
            overlap->second = max;
            return true;
        }

        return false;
    }
    
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {

        int last_valid_inteval = intervals.size() -1;

        // search first match.
        int op = -1;
        int cloest_idx = -1;
        int cloest_offset = INT32_MAX;
        bool cloest_as_left = false;

        // TODO : add binary search to increase  search performance
        for (int i = 0 ; i <= last_valid_inteval; i++) {
            std::vector<int> &candidate = intervals[i];
            std::pair<int, int> overlap;

            if (this->isOverlap(candidate, newInterval, &overlap)) {
                candidate[0] = overlap.first;
                candidate[1] = overlap.second;
                op = i;
                break;
            } else {
                int atLeft = candidate[0] - newInterval[1];     // true if  >0
                int atRight = newInterval[0] - candidate[1];  // true if > 0

                if (atLeft > 0) {
                    if (cloest_offset > atLeft) {
                        cloest_idx = i;
                        cloest_offset = atLeft;
                        cloest_as_left = true;
                    }
                } else if (atRight > 0) {
                    if (cloest_offset > atRight) {
                        cloest_idx = i;
                        cloest_offset = atRight;
                        cloest_as_left = false;
                    }
                }
            }
        }

        // merge all element behined list
        if (op != -1) {
            std::vector<int> &vA = intervals[op];

            int erase_start = -1;
            int erase_end = -1;
            for (int j = op + 1 ; j <= last_valid_inteval; j++) {
                std::vector<int> &vB = intervals[j];
                std::pair<int, int> overlap;

                if (this->isOverlap(vA, vB, &overlap)) {
                    vA[0] = overlap.first;
                    vA[1] = overlap.second;

                    if (erase_start == -1) erase_start = j;
                    erase_end = j;
                }
            }

            // remove redumdent item
            if (erase_start != -1 && erase_end != -1) {
                intervals.erase(intervals.begin() + erase_start, intervals.begin() + erase_end +1);
            }
        } else {
            if (intervals.size() ==0) {
                intervals.emplace_back(newInterval);
            } else {

                if (cloest_as_left) {  // add as last one
                    intervals.insert(intervals.begin() + cloest_idx, newInterval);
                } else {    // add as frist one
                    intervals.insert(intervals.begin() + cloest_idx + 1, newInterval);
                }
            }
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

void add_invevral(int left, int right, std::vector<int> *data) {
    data->emplace_back(left);
    data->emplace_back(right);
}

int main()
{
    std::vector<std::vector<int>> data;
    std::vector<int> intevral;
    // add_slice(1, 3, &data);
    // add_slice(6, 9, &data);
    // add_invevral(2, 15, &intevral);

    // add_slice(1, 3, &data);
    // add_slice(60, 90, &data);
    // add_invevral(15, 20, &intevral);

    add_slice(1, 5, &data);
    add_invevral(6, 8, &intevral);

    // add_slice(1, 2, &data);
    // add_slice(3, 5, &data);
    // add_slice(6, 7, &data);
    // add_slice(8, 10, &data);
    // add_slice(12, 16, &data);
    // add_invevral(2, 5, &intevral);

    // add_slice(1, 5, &data);
    // add_invevral(12, 13, &intevral);

    Solution ss;
    std::vector<std::vector<int>> ret = ss.insert(data, intevral);

    for (int i = 0 ; i < ret.size(); i++) {
        printf("%d %d\n", ret[i][0], ret[i][1]);
    }

 
    return 0;
}