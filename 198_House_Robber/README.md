[198] House Robber
=======================

Accroding to topic, for every house , we have 2 chooses:
- steal house [i]
- Not steal house [i]


Let we think about these two chooses:
- <b>steal house [i]</b>: We take money at house [i]
- <b>Not steal house [i]</b>: We doesn't money at house [i],

What is the best profit at houst i?  let we list that:

    for 1 House:
    H[0]
      ^
      |
    you have no choose, do that, best profit : H[0]

    for 2 House:
    H[0], H[1]
      ^     ^
      |     | 
      |     you have 2 choose, take H[0] or H[1]
        you have no choose, take H[0]

    for 3 House:
    H[0], H[1], H[2]
      ^     ^     ^
      |     |     |
      |     |     you have 3 choose:
      |     |       - take H[0]
      |     |       - take H[1]
      |     |       - take H[0] + H[2]   
      |     you have 2 choose, take H[0] or H[1]
      you have no choose, take H[0]

    for 4 House:
    H[0], H[1], H[2], H[3]
      ^     ^     ^    ^
      |     |     |    |
      |     |     |    you have ?
      |     |     |
      |     |     you have 3 choose:
      |     |       - take H[0]
      |     |       - take H[1]
      |     |       - take H[0] + H[2]   
      |     you have 2 choose, take H[0] or H[1]
      you have no choose, take H[0]

let we split 4 house problem as following:

    -----------------*-------
    P[0]  P[1]  P[2] | P[i]     (best profit)
    -----------------|-------
    H[0], H[1], H[2] | H[3]
    -----------------*-------

Hot to get best profit at P[i] ? In a additional choose, just take all of H[i -1], H[i -2] H[i -3] ....., but, we can't
steal two adjacent houst at one night, let we list all of situations:

  A. Steal houst[i]:
    Our best profit would be : P[i-2] + H[i]

  B. Not Steal houst[i]:
    Our best profit would be : P[i-1] , because we do nothing at i, just keep all profit.

Accroding to these, we have 2 situations at houst[i], { P[i-2]+ H[i] , P[i-1] }. To archive best profit,
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