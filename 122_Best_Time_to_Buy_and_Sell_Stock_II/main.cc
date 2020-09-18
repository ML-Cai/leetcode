#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <unordered_map>

// Runtime: 8 ms, faster than 96.71% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 13.1 MB, less than 71.77% of C++ online submissions for Best Time to Buy and Sell Stock II.
class Solution {
public:

    int maxProfit(std::vector<int>& prices) {
        /** Try to think about following datas.
         *    [1, 2, 3, 4, 5]
         *  
         *     if we buy 1 and sell at 5 , we got 4 profit.
         *     but, if we buy 1 and sell at 2 ->  buy 2 sell at 3 -> buy 3 sell at 4 -> buy 4 sell at 5, we got 4 profit at same time.
         *     
         *     so, if we peek stock price at (i+1) and found the prices large than current price(i), we can buy (i+1), and sell it at (i) time.
        */         
        // [7, 1, 2, 3, 9, 1, 2, 10]
        // [1, 2, 3, 4, 5, 6, 7]
        // [1, 3, 1, 3, 1, 3, 1]
        // [1, 2, 3, 4, 5, 3, 1]
        int ret = 0;
        for (int i = 1 ; i < prices.size(); i++) {
            ret += std::max(0, prices[i] - prices[i-1]);
        }
        
        return ret;
    }
};

int main()
{
    std::vector<int> data;
    data.emplace_back(7);
    data.emplace_back(1);
    data.emplace_back(5);
    data.emplace_back(3);
    data.emplace_back(6);
    data.emplace_back(4);

    Solution ss;
    printf("%d\n ", ss.maxProfit(data));

    return 0;
}
