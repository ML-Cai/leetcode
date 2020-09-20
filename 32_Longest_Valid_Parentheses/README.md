[32] Longest Valid Parentheses


If a pair of () is valid, it would be following style:
    ... (...)

    ... is non-determined  pattern, such as "((()" , "((((((()"
    
We can simply exoress the problem as "previous valid" + "current is valid".

The first of our idea, is to check parnetheses valid at current step i or not. Once it valid, we must check 
how many previous parnetheses valid before i, and accumlated them.

But, how to check previous parnetheses? and the range of parnetheses?
think about that :

    One valid parnetheses

         A                      B
        ...       (            ...           )

    We have 2 range of previous parentheses need be considered, A and B.

    
    First let we define the sequence:

                       
          (       )
        p[i-1]   p[i]

    If we define a p[] as the profit at step [i], once parentheses valid, plus 1 at p[].
    so, at p[i-1] step, p [i-1] would be 0, due to no valid parentheses found, at p[i] step, it will be plused as 1.

    but, each pair of parentheses may not closer to each other. it would have a distance, so we
    extend the formula as :

          |<--------------|  d = distance
          (       ....    )
        p[i-d]          p[i]


    Just think about A only:

         A               
        ...       (       )
                p[i-d]   p[i]            
          ?       0        1  : profit   , we got 1 profit if parentheses valid


         A
          )            (       )
        p[i-d-1]    p[i-d]   p[i]            
          ?            0       1+?  : profit
         
          (            (       )
        p[i-d-1]    p[i-d]   p[i]            
          ?            0       1+?  : profit

        To consider the profit of section A, we can defined formula as:
            if valid , p[i] = 1 +  p[i-d-1]

        such as :

        Example A-1:
            (    )     (     )
            0    -1    0    -1   Distance
            0    1     0     1   Profit (at i)
            0    1     0     2   Total profit with formula A,  if valid, p[i] = 1 + p[i-d-1]
           

    Just think about B only:
                    B
          (        ....        )
        p[i-d]               p[i]            
          0          ?         1  : profit   , we got 1 profit if parentheses valid


        For case B, it would be a valid parentheses, or p[i] does'nt match to p[i-d]

                       B
          (      ......... )          )
        p[i-d]          p[i-1]       p[i]            
          0              ?           1  : profit   , we got 1 profit if parentheses valid

        Due to A, no mater how many parentheses valid in section a, it would sumarized to p[] of last valid ),
        in this case, it will sumarized to p[i-1].
        So, we can define foumula B as :
            if valid , p[i] = 1 + p[i-1]

        Example B-1:
            (     (     )     )
            0     0    -1     -2   Distance
            0     0     1     1    Profit (at i)
            0     0    1      2    Total profit with formula B,  if valid, p[i] = 1 + p[i-1]


    Finally, we can merge A and B as :
           A                         B
          ...         (            ...           )
        p[i-d-1]    p[i-d]         p[i-1]       p[i]      

        Formula :
            if valid :
                p[i] = 1 + p[i-1] + p[i-d-1]
            else
                p[i] = 0

    Example:
    /*
                
    (  )  (  (  (  (  )  )  )
    0  1  0  0  0  0 -1 -2 -5    distance
    
    0  1  0  0  0  0  1  2  3     if 1 : 1 +[i -1]               // check previous is valid?
    0  1  0  0  0  0  1  1  1     if 1 : 1 +[i - distance -1]    // check my parnet's previois is valid?
                                       |
                                     merge
                                       |
    0  1  0  0  0  0  1  2  3     if 1 : 1 + [i -1] + [i - distance -1]




    (  )  (  (  (  )  )  )
    0  1  0  0  0  1  2  5
    
    0  1  0  0  0  1  1  2     if 1 : 1 +[i - distance -1]
    0  1  0  0  0  1  2  3     if 1 : [i] +[i -1]
    
    0  1  0  0  0  1  2  4     if 1 : 1 + [i -1] + [i - distance -1]

    */





