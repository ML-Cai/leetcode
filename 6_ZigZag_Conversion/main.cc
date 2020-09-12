#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 20 ms, faster than 91.25% of C++ online submissions for ZigZag Conversion.
// Memory Usage: 7.9 MB, less than 84.81% of C++ online submissions for ZigZag Conversion.

// TODO : Add a lookup table for each step at dx.

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (s.size() <= numRows) return s;
        if (numRows == 1) return s;

        // create map by row
        size_t s_size = s.size();

        /* dx, dy
                  0     1    2    (dx)
               +-----------------   
             0 |  P     I    N
             1 |  A   L S  I G
             2 |  Y A   H R
             3 |  P     I
            (dy) 
        */
        const size_t INDEX_STEP = (numRows + (numRows -2));
        const size_t MAX_DY = (numRows -1);
        std::string ret;
        for (size_t dy = 0; dy < numRows ; dy++) {  // dy
            size_t dx = 0;

            while (1) {  // dx
                // size_t index = dx * (numRows + (numRows -2)) + dy;
                size_t index = dx * INDEX_STEP + dy;

                if (index < s.size()) {
                    ret += s[index];
                } else {
                    break;
                }

                // if (dy > 0 && dy < (numRows -1)) {
                if (dy > 0 && dy < MAX_DY) {
                    // size_t next_dx_index = (dx +1) * (numRows + (numRows -2));
                    size_t next_dx_index = (dx +1) * INDEX_STEP;
                    size_t z_index = next_dx_index - dy;

                    if (z_index < s.size()) {
                        ret += s[z_index];
                    } else {
                        break;
                    }
                }
                dx++;
            }

        }

        return ret;
    }
};

int main()
{
    Solution ss;

    printf("%s\n", ss.convert("AB", 1).c_str());
    // printf("%s\n", ss.convert("PAYPALISHIRING", 3).c_str());
    // printf("%s\n", ss.convert("PAYPALISHIRING", 4).c_str());
    
    return 0;
}