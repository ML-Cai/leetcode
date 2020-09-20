[63] Unique Paths II

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
        p[0][0], p[0][1], p[0][2] , p[0][3] ............, p[0][n]
        p[1][0], ...
        p[2][0], ...
        ....
        p[m][0]
    */


With obstacle, we can update formula as following:

    /**
                            p(x, y-1)    
                            |    
                            |    
                            |   
                            |    
            +---------------+
            p(x-1, y)       p(x, y)                   
        
            p(x, y) = p(x-1, y) * (1 - ob(x -1, y)) + 
                      p(x, y-1) * (1 - ob(x, y -1)) + 
        
    */

In boundary check of y = 0, we must care about the init value of p.
If any obstacle placed on xi at first row, the xi+1, xi+2 xi+3 will blocking.

    /**
        o[0][0], o[0][1], o[0][2] , o[0][3] ............, o[0][n]
        o[1][0], ...
        o[2][0], ...
        ....
        o[m][0]

        obstacle
        0   0   0   0   1   0   0   0 
        0   0   0   0   0   0   0   0 
        0   0   0   0   0   0   0   0 
        0   0   0   0   0   0   0   0 

        p of first row
        1   1   1   1   0   0   0   0
        ?   ?   ?   ?   ?   ?   ?   ?
        ?   ?   ?   ?   ?   ?   ?   ?
        ?   ?   ?   ?   ?   ?   ?   ? 

    */

Same problem as x =0, y=0 need consider the boundary too,

    /**
        o[0][0], o[0][1], o[0][2] , o[0][3] ............, o[0][n]
        o[1][0], ...
        o[2][0], ...
        ....
        o[m][0]

        obstacle
        0   0   0   0   0   0   0   0 
        0   0   0   0   0   0   0   0 
        1   0   0   0   0   0   0   0 
        0   0   0   0   0   0   0   0 

        p of first colum
        1   0   0   0   0   0   0   0
        1   ?   ?   ?   ?   ?   ?   ?
        0   ?   ?   ?   ?   ?   ?   ?
        0   ?   ?   ?   ?   ?   ?   ?

    */