#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        /*
        
          ["1", "0", "1", "0", "1"],
          ["1", "0", "1", "0", "1"],
          ["1", "1", "1", "0", "1"],
          ["0", "0", "1"," 0", "0"]
          ["0", "1", "1"," 0", "0"]
          ["0", "0", "0"," 0", "0"]
        
        */
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        
        int height = grid.size();
        int width = grid[0].size();
        size_t oID_counter = 2;
        std::unordered_set<size_t> unique_oID;
        int **label = new int* [height];
        
        for (size_t i = 0 ; i < height ; i++) {
            label[i] = new int [width];
            memset(label[i], 0, sizeof(int) * width);
        }
        
        
        // first node
        if (grid[0][0] == '1') {
            label[0][0] = oID_counter;
            unique_oID.emplace(oID_counter);
            oID_counter++;
        } else {
            label[0][0] = 0;
        }
        
        // parse 1st row
        for (size_t dx = 1 ; dx < width ; dx++) {
            if (grid[0][dx] == '0') continue;
                
            if (label[0][dx-1] != 0) {
                label[0][dx] = label[0][dx -1];
            } else {
                label[0][dx] = oID_counter;
                unique_oID.emplace(oID_counter);
                oID_counter++;
            }
        }
        
        // parse 1st column
        for (size_t dy = 1 ; dy < height ; dy++) {
            if (grid[dy][0] == '0') continue;
            
            if (label[dy -1][0] != 0) {
                label[dy][0] = label[dy-1][0];
            } else {
                label[dy][0] = oID_counter;
                unique_oID.emplace(oID_counter);
                oID_counter++;
            }
        }
        
        // others
        for (size_t dy = 1 ; dy < height ; dy++) {
            for (size_t dx = 1 ; dx < width ; dx++) {
                if (grid[dy][dx] == '0') continue;
                
                // check top & left
                const int v_top  = label[dy -1][dx];
                const int v_left = label[dy][dx -1];

                // all water, add new oID
                if ((v_top == 0) && (v_left == 0)) {
                    label[dy][dx] = oID_counter;
                    unique_oID.emplace(oID_counter);
                    oID_counter++;
                    
                } else if (v_left == 0) {
                    label[dy][dx] = v_top;
                    
                } else if (v_top == 0) {
                    label[dy][dx] = v_left;
                    
                } else if (v_top == v_left) { 
                    label[dy][dx] = v_top;  // give any one if same.
                    
                } else {
                    // is top oID not same as left oID ?
                    // remove one of them
                    auto iter = unique_oID.find(v_left);
                    if (iter != unique_oID.end()) {
                        unique_oID.erase(iter);
                    }
                }
            }
        }
        
        // return count of unique_oID
        return unique_oID.size();
    }
};

int main()
{
    std::vector<std::vector<char> >data;
    std::vector<char> p0(3);
    p0[0] = '1';
    p0[1] = '1';
    p0[2] = '1';
    data.emplace_back(p0);
    p0[0] = '0';
    p0[1] = '1';
    p0[2] = '0';
    data.emplace_back(p0);
    p0[0] = '1';
    p0[1] = '1';
    p0[2] = '1';
    data.emplace_back(p0);

    Solution ss;
    printf("%d\n ", ss.numIslands(data));

    return 0;
}
