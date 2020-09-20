#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>
#include <stack>
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        /**
                            p(x, y-1)    
                            |    
                            |    
                            |   
                            |    
            +---------------+
            p(x-1, y)       p(x, y)                   
        
            p(x, y) = p(x-1, y) * (1 - ob(x -1, y)) + 
                      p(x, y-1) * (1 - ob(x, y -1)) + 
        
        */
        
        if (obstacleGrid.size() ==0) return 0;
        if (obstacleGrid[0].size() ==0) return 0;
        
        int width = obstacleGrid[0].size();
        int height = obstacleGrid.size();
        int *m = new int[width * height];
        memset(m, 0, sizeof(int)*width*height);
        
        
        for (int dy = 0; dy < height; dy++) {
            if (obstacleGrid[dy][0] == 0) {
                m[dy *width] = 1.0;
            } else {
                break;
            }
        }
        
        for (int dx = 0; dx < width; dx++) {
            if (obstacleGrid[0][dx] == 0) {
                m[dx] = 1.0;
            } else {
                break;
            }
        }
        
        for (int dy = 1 ; dy < height ; dy++) {
            for (int dx = 1 ; dx < width ; dx++) {
                int cur_idx = dy * width +dx;
                int top_idx = cur_idx - width;
                int left_idx = cur_idx -1;
                
                m[cur_idx] = m[top_idx] * (1 - obstacleGrid[dy -1][dx]) +
                             m[left_idx] * (1 - obstacleGrid[dy][dx-1]);
            }
        }

        int ret = m[width*height -1] * (1 -obstacleGrid[height -1][width -1]);
        delete []m;
        
        return ret;
    }
};

int main()
{
    Solution ss;
    // printf("%d\n", ss.isMatch("aa", "a*"));
    printf("%d\n", ss.longestValidParentheses(")()())") );
    return 0;
}