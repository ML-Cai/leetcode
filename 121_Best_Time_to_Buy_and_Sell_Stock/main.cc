#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <unordered_map>

// Runtime: 4 ms, faster than 99.85% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 13 MB, less than 85.76% of C++ online submissions for Best Time to Buy and Sell Stock.

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        int profit = 0;
        size_t candi_idx = 0;   // maybe i will buy stock at this place, but, i want check the next prices is large or not?
        
        for (size_t i = 1 ; i < prices.size() ; i++) {
            // if next prices is large than candia, then i'sure to buy candidate, and update profit
            if (prices[i] > prices[candi_idx]) {    
                int p = prices[i] - prices[candi_idx];
                profit = std::max(profit, p);
            } else {
                // else, give up candidate index, and select current i as new candidate index.
                candi_idx = i;
            }
        }
       
        return profit;
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
