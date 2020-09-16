#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <unordered_map>
// Runtime: 8 ms, faster than 99.90% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 11.3 MB, less than 73.58% of C++ online submissions for Search a 2D Matrix.

// class Solution {
// public:
//     bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
//         bool ret = false;

//         if (matrix.size() == 0) return false;
//         else if (matrix[0].size() ==0) return false;
//         else if (matrix[0][0] > target) return false;
//         else if (matrix.back().back() < target) return false;

//         int idx_slot = -1;
//         do {
//             int idx_A = 0;
//             int idx_B = matrix.size() - 1;

//             while (idx_A <= idx_B) {
//                 int idx_C = idx_A + (idx_B - idx_A) / 2;
//                 const int vC = matrix[idx_C][0];

//                 if (vC < target) {
//                     idx_A = idx_C + 1;
//                 } else if (vC > target) {
//                     idx_B = idx_C - 1;
//                 } else {
//                     idx_slot = idx_C;
//                     break;
//                 }
//             }

//             if (idx_slot == -1) {
//                 idx_slot = idx_B;
//             }
//         } while (false);

//         if (idx_slot != -1) {
//             const std::vector<int> &data_src = matrix[idx_slot];
//             int idx_A = 0;
//             int idx_B = data_src.size() -1;

//             while (idx_A <= idx_B) {
//                 int idx_C = idx_A + (idx_B- idx_A) / 2;
//                 const int v = data_src[idx_C];

//                 if (v < target) {
//                     idx_A = idx_C +1;
//                 } else if (v > target) {
//                     idx_B = idx_C -1;
//                 } else {
//                     return true;
//                 }
//             }
//         }


//         return ret;
//     }
// };


class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        bool ret = false;

        if (matrix.size() == 0) return false;
        else if (matrix[0].size() ==0) return false;
        else if (matrix[0][0] > target) return false;
        else if (matrix.back().back() < target) return false;

        const int width = matrix[0].size();
        int idx_A = 0;
        int idx_B = (matrix.size() - 1) * width + width -1;

        while (idx_A <= idx_B) {
            const int idx_C = idx_A + (idx_B - idx_A) / 2;
            const int dx = idx_C % width;
            const int dy = idx_C / width;
            const int vC = matrix[dy][dx];

            if (vC < target) {
                idx_A = idx_C + 1;
            } else if (vC > target) {
                idx_B = idx_C - 1;
            } else {
                return true;
            }
        }
        return ret;
    }
};

int main()
{
    std::vector<std::vector<int>> data;
    int target;
    // int a[3][3] = {{1, 1, 1},
    //                {1, 0, 1},
    //                {1, 1, 1}};
    // data.emplace_back(std::vector<int>(a[0], a[0] + 3));
    // data.emplace_back(std::vector<int>(a[1], a[1] + 3));
    // data.emplace_back(std::vector<int>(a[2], a[2] + 3));

    int a[3][4] = {{1, 3, 5, 7},
                   {10, 11, 16, 20},
                   {23, 30, 34, 50}};
    data.emplace_back(std::vector<int>(a[0], a[0] + 4));
    // data.emplace_back(std::vector<int>(a[1], a[1] + 4));
    // data.emplace_back(std::vector<int>(a[2], a[2] + 4));
    target = 2;


    Solution ss;
    printf("%d\n", ss.searchMatrix(data, target));

    return 0;
}