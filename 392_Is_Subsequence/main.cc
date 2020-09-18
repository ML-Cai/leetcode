#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

class Solution {
public:
    bool isSubsequence(std::string str, std::string temp) {
        if (str.size() > temp.size()) return false;
        
        bool ret = true;
        
        size_t temp_idx = 0;
        for (size_t i = 0 ; i < str.size(); i++) {
            const char c = str[i];  // get check strings
            
            // find at templated, check c exist or not.
            while ((temp_idx < temp.size()) && (c != temp[temp_idx]) ) {
                temp_idx++;
            }
            
            // if compared to the end of string, no char same with c, just break.
            if (temp_idx == temp.size()) {
                ret = false;
                break;
            } else {
                temp_idx++;     // move to next template position
            }
        }
        return ret;
    }
};

int main()
{
    Solution ss;
    printf("%d\n", ss.isSubsequence("abc", "ahbgdc"));


    return 0;
}