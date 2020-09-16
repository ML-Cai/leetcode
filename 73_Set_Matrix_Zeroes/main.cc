#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <unordered_map>
// Runtime: 24 ms, faster than 93.60% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 13.3 MB, less than 70.00% of C++ online submissions for Set Matrix Zeroes.

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {

        bool keep_row_0 = true;
        bool keep_col_0 = true;

        for (size_t dy = 0; dy < matrix.size(); dy++) {
            std::vector<int> &m_x = matrix[dy];

            if (m_x[0] == 0) {
                keep_col_0 = false;
            }

            for (size_t dx = 0; dx < m_x.size(); dx++) {
                if (m_x[dx] == 0) {
                    matrix[dy][0] = 0;
                    matrix[0][dx] = 0;
                }
            }

            if (dy == 0 && matrix[dy][0] == 0) {
                keep_row_0 = false;
            }
        }


        do {
            std::vector<int> &ref_x = matrix[0];

            for (size_t dx = 1; dx < ref_x.size() ; dx++) {
                if (ref_x[dx] == 0) {
                    for (size_t dy = 0; dy < matrix.size(); dy++) {
                        matrix[dy][dx] = 0;
                    }
                }
            }
        } while (false);

        // remove by row
        do {
            for (size_t dy = 1; dy < matrix.size() ; dy++) {
                std::vector<int> &m_x = matrix[dy];

                if (m_x[0] == 0) {
                    memset((void *)m_x.data(), 0, sizeof(int) * m_x.size());
                }
            }
        } while (false);

        do {
            if (!keep_row_0) {
                std::vector<int> &m_x = matrix[0];
                memset((void *)m_x.data(), 0, sizeof(int) * m_x.size());
            }
            if (!keep_col_0) {
                for (size_t dy = 0; dy < matrix.size(); dy++) {
                    matrix[dy][0]= 0;
                }
            }
        } while (false);

    }
};




int main()
{
    std::vector<std::vector<int>>data;
    // int a[3][3] = {{1, 1, 1},
    //                {1, 0, 1},
    //                {1, 1, 1}};
    // data.emplace_back(std::vector<int>(a[0], a[0] + 3));
    // data.emplace_back(std::vector<int>(a[1], a[1] + 3));
    // data.emplace_back(std::vector<int>(a[2], a[2] + 3));

    int a[3][4] = {{0, 1, 2, 0},
                   {3, 4, 5, 2},
                   {1, 3, 1, 5}};
    data.emplace_back(std::vector<int>(a[0], a[0] + 4));
    data.emplace_back(std::vector<int>(a[1], a[1] + 4));
    data.emplace_back(std::vector<int>(a[2], a[2] + 4));

    Solution ss;
    ss.setZeroes(data);

    for (int i = 0 ; i < data.size(); i++) {
        for (int ii = 0 ; ii < data[i].size(); ii++) {
            printf("%d ", data[i][ii]);
        }
        printf("\n");
    }

    return 0;
}