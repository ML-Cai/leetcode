[213] House Robber II
=======================

Same as [198] House Robber, accroding to topic, for every house , we have 2 chooses:
- Do
- Not to do

Accroding to [192], we have 2 situations at houst[i], { P[i-2]+ H[i] , P[i-1] }. To archive best profit,
we must choose this biggest profit at houst i, so, the final profit at houst i would be :
  - P[i] = max (P[i-2]+ H[i] , P[i-1])

We got a max profit formula, let we defined edge case:
  - P[0] :
    - P[0] = max (P[-2]+ H[0] , P[-1])
      - This formual will lead memory issues due to -1, -2 access, so, we can assume we are pauper before we steal any houst, with this condition, we can set P[-?] as 0, so new P[0] would be:
    - P[0] = max (0+ H[0] , 0)
    - P[0] =         H[0]

  - P[1]
    - P[1] = max (P[-1]+ H[1] , P[0])
      - With above assumation, P[-1] woulbe be 0, so :
    - P[1] = max (0 + H[1], P[0])
    - P[1] = max (H[1], P[0])

  - P[2]
    - P[2] = max (P[0]+ H[2] , P[1])

  - P[3]
    - P[3] = max (P[1]+ H[3] , P[2])

  - ....
  
  - P[i]
    - P[i] = max (P[i-2]+ H[i] , P[i-1])

In this topic, houses are arranged in a circile, so we must prevent to choose n and n-1 at same time,
To do that, we can use following strategy:
  - Remove house 0, find max profit
  - Remove house n, find max profit
  - Choose max profit.








