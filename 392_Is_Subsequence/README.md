[392] Is Subsequence
=============

Give 2 string s and t, check if s is subsequence of t.

> Input: s = "abc", t = "ahbgdc"
> Output: true


My Solution:

1. Use an index (temp_idx) pointer to head of t.
>     t : "ahbgdc"
>          ^
>          temp_idx
   
2. take first value of s

>     s : "abc"
>          ^
>          i

3. Compare t[temp_idx] & s[i]
    - If t[temp_idx] != s[i] , increase temp_idx and redo step 3 until temp_idx out of range.
    - If t[temp_idx] == s[i] , then we can add i by 1 to search next value, and add temp_idx by 1 to skip current value (due to t[temp_idx] mapped to s[i]).
   
4. Run step 3. until i out of range or temp_idx out of range.
    - If i out of range, it means that we search all char successfully at s.
    - Else if temp_idx out of range, it means at least one char of c not found at t.

>     t : "ahbgdc"       s : "abc"
>          ^                  ^ 
>          temp_idx           i
>
>      t[temp_idx] == s[i], temp_idx++, i++

>     t : "ahbgdc"       s : "abc"
>           ^                  ^ 
>           temp_idx           i
>
>      t[temp_idx] != s[i], temp_idx++

>     t : "ahbgdc"       s : "abc"
>            ^                 ^ 
>            temp_idx          i
>
>      t[temp_idx] == s[i], temp_idx++, i++

>     t : "ahbgdc"       s : "abc"
>             ^                 ^ 
>             temp_idx          i
>
>      t[temp_idx] != s[i], temp_idx++

>     t : "ahbgdc"       s : "abc"
>              ^                ^ 
>              temp_idx         i
>
>      t[temp_idx] != s[i], temp_idx++
> 
>     t : "ahbgdc"       s : "abc"
>               ^               ^ 
>               temp_idx        i
>
>      t[temp_idx] == s[i], temp_idx++
>      i if out of range, s is subsequence.

