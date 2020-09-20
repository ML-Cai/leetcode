#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>
#include <stack>

class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
              *---------> (x, y -1)
              |
              |
              v         *  (x, y)
             (x-1, y)

             
             p(x, y) = p (x -1, y) + p(x, y-1)
             
        */
        const int width = n;
        const int height = m;
        int * p = new int[m * n];
        memset(p, 0, sizeof(int) *m *n);
        
        /**
         *    p[0][0], p[1], p[2] , p[3] ............, p[n]
         *    p[1][0], ...
         *    p[2][0], ...
         *    ....
         *    p[m][0]
         */
        // dut to  p(x, y) = p (x -1, y) + p(x, y-1), if y = 0; is will out-of-bound, so we define the data first.
        for (int dx = 0 ; dx < width ; dx++) {
            p[dx] = 1;
        }

        // dut to  p(x, y) = p (x -1, y) + p(x, y-1), if x = 0; is will out-of-bound, so we define the data first.
        for (int dy = 0 ; dy < height ; dy++) {
            p[dy * width] = 1;
        }

        for (int dy = 1; dy < height; dy++) {
            for (int dx = 1; dx < width; dx++) {
                int cur_idx = dy *width + dx;
                int top_idx = cur_idx - width;
                int left_idx = cur_idx - 1;

                p[cur_idx] = p[top_idx] + p[left_idx];
            }
        }

        return p[m*n-1];
    }
};

int main()
{
    Solution ss;
    // printf("%d\n", ss.isMatch("aa", "a*"));
    printf("%d\n", ss.uniquePaths(7, 3)) );
    return 0;
}