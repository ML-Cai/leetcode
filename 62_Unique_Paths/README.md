[62] Unique Paths

Robot can only move either down or right, in other words, at each grid, robot come from top or right

so we can defined the model as :

    /*
                            p(x, y-1)    
                            |    
                            |    
                            |   
                            |    
            +---------------+
            p(x-1, y)       p(x, y)                   
        
            p(x, y) = p (x -1, y) + p(x, y-1)
             
    */

In programming, we must care about the boundary of grids in x-1 and y-1, see following array definations: 
  - (x -1) will out-of-bound when x = 0
  - (y -1) will out-of-bound when y = 0

Due to this reason, we must set these data first.

    /**
        p[0][0], p[1], p[2] , p[3] ............, p[n]
        p[1][0], ...
        p[2][0], ...
        ....
        p[m][0]
    */


