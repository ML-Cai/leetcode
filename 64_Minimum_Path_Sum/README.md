[64] Minimum Path Sum

Similar ideas as [62] Unique Paths and [63] Unique Paths II, 

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
        
            for [62] : p(x, y) = p(x -1, y) + p(x, y-1)

            for this problem : cost(x, y) =  min{cost(x -1, y),
                                                 cost(x, y-1)} + cost(x, y)
             
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

