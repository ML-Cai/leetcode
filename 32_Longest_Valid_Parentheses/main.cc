#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>
#include <stack>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        /*
           
           (  )  (  (  (  )  )  )
           0  1  0  0  0  1  2  5
           
           0  1  0  0  0  1  1  2     if 1 : 1 +[i - distance -1]
           0  1  0  0  0  1  2  3     if 1 : [i] +[i -1]
         
           0  1  0  0  0  1  2  4   if 1 : 1 + [i -1] + [i - distance -1]
     
        */
        
        // std::vector<int> profit(s.size(), 0);
        std::stack<size_t> pat_stack;  //  "(" index
        std::vector<int> profit(s.size(), 0);    // if ()match : [i] = 1 + [i -1] + [i - distance -1]
        int max_profit =0;
      
        for (size_t i = 0 ; i < s.size(); i++) {
            if (s[i] ==')') {
                // match
                if (pat_stack.size() > 0) {
                    size_t parnet_index = pat_stack.top();
                    
                    // [i] = 1 + [i -1] + [i - distance -1]
                    size_t distance = i - parnet_index;
                    profit[i] = 1;
                    if (i > 0) profit[i] += profit[i-1];
                    if (parnet_index > 0) profit[i] += profit[parnet_index-1];
                
                    // get max
                    max_profit = std::max(max_profit, profit[i]);
                    
                    // remove top
                    pat_stack.pop();
                }
            } else {
                pat_stack.emplace(i);
            }
        }
        
        return max_profit *2;
    }
};

int main()
{
    Solution ss;
    // printf("%d\n", ss.isMatch("aa", "a*"));
    printf("%d\n", ss.longestValidParentheses(")()())") );
    return 0;
}