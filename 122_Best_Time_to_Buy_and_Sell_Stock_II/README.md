[122] Best Time to Buy and Sell Stock II
================

Try to think about following datas.
    [1, 2, 3, 4, 5]
    
if we:
  - buy 1 and sell at 5 , we got 4 profit.

But, if we :
  - buy stock at time (1), and sell at time(2) ->
  - buy stock at time (2), and sell at time(3) -> 
  - buy stock at time (3), and sell at time(4) -> 
  - buy stock at time (4), and sell at time(5), we got 4 profit at same time.

Now, let we list all situations about adjacent timeline.
  1. price(i) = price (i -1) , and got 0 profit.
  2. price(i) < price (i -1) , and got - profit.
  3. price(i) > price (i -1) , and got + profit.
  
if we go through all i, and keep 1 and 3 then we can get maximum profit.
above algorithm has a condiation : <b> we can sell previous stock and buy new stock at same day. </b>.

Therefore, the algorithm would be : if we peek stock price at (i+1) and found the prices large than current price(i), we can buy (i+1), and sell it at (i) time.

> 
> int ret = 0; <br>
> for (int i = 1 ; i < prices.size(); i++) { <br>
>     ret += std::max(0, prices[i] - prices[i-1]); <br>
> }  <br>

