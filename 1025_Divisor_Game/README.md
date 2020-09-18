[1025] Divisor Game
======================

See following table, we can found 2 basic rule.
  - If alice be the picker of odd number , 100% lose.
  - If alice be the picker of even number , 100% win.

For <b>even number</b>, the first picker could pick 1 as optimal value, and the next N value would be <b>odd number</b>, therefore, the next picker only even number for chosen.

As N > 3, No matter what value be chosen, the final x for choosen would be 2 or 3,  so, we must keep <b>2</b> as our last choosen value. But, how can we be the frist one to choose 2 ?

<b>"Let odd number be chosen by next picker"</b>, and then, the next picker would be:
  1. current N is odd value, next picker pick x=1 as next,  next N would allways be even for us.
  2. current N is odd value, next picker pick x= odd number as next, next N would allways  be even for us. (note: (odd number - odd number) = even number)
  3. current N is odd value, next picker pick x= even number is not possible.

With this condition, if init N is even number, we can pick 1 to force next N as odd number to achieve our purpose.

But, if init N is odd value:
  1. we have no choose to choose 1, when N is prime number,  and it will let next N be even ... next player will 100% win.
  2. only odd number would be candidate x for odd number N, so, we have no choose ... select any odd number will generate a event number in next step.


/**
        
         if alice win 100%, she must choose value 1 as final value.
         
         if N is powered by 2, (2^N),  N > 1, 100% lose, 
         
         N = 2 : 
         -------------------------------------------------------> N = 2, picker 100% win
         
         N = 3 : 
         -------------------------------------------------------> N = 3, picker 100% lose
         
         
         N = 4 , x would be 1,  2
           Alice chooce [2] :
             N = 2 for Bob.
               Alices lose.  due to N = 2 picker 100% win.
           
           Alice chooce [1]:
             N = 3 for Bob
               Bob lose.  due to N = 3 picker 100% lose.
        ---------------------------------------------------------> N= 4, picker 100% win , just choose 1
        
        N = 5 , x would be 1
           Alice chooce 1 :  
             N = 4 for Bob
               Bob win ---> N=4,  pciker 100% win  
        ---------------------------------------------------------> N= 5, picker 100% lose
        
        N = 6 , x would be 1, 2, 3
          Alice choose 1:
            N = 5 for bobo:
              Bob lose.  due to N = 5 picker 100% lose.
            
          Alice choose 2:
            N = 4 for bob:
               Bob win.  due to N = 4 picker 100% win.
        
          Alice choose 3:
            N = 3 for bob:
               Bob lose.  due to N = 3 picker 100% lose.
        ---------------------------------------------------------> N= 6, picker 100% win, just select 1
        
        N = 7 , x would be 1
           Alice chooce 1 :  
             N = 6 for Bob
               Bob win ---> N=6,  pciker 100% win  
        ---------------------------------------------------------> N= 7, picker 100% lose
        
        N = 8 , x would be 1, 2, 4
           Alice choose 1 :  
             N = 7 for bob:
                Bob lose.  due to N = 7 picker 100% lose.
                
           Alice choose 2 :  
             N = 6 for bob:
                Bob win.  due to N = 6 picker 100% win.
         
           Alice choose 4:
             N = 4 for bob:
                Bob win.  due to N = 4 picker 100% win.
        ---------------------------------------------------------> N= 8, picker 100% win just select 1
        
        N = 9, x would be 1, 3
           Alice choose 1:
             N = 8 for bob:
               Bob win.  due to N = 8 picker 100% win.
        
           Alice choose 3:
             N = 6 for bob:
               Bob win.  due to N = 6 picker 100% win. 
               
        ---------------------------------------------------------> N= 9, picker 100% lose
        */