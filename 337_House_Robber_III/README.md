[337] House Robber III
=======================

Similar problem as [213] House Robber II, accroding to topic, for every house , we have 2 chooses:
- Steal house [i]
- Not to steal house [i]

Different to [213]  & [198], this problem extend list to binary tree, but the key rule in this problem is same as [198],
<b>We can't steal adjacent house at node</b> , such as :

              [0]
            /     \
           /       \
         [1]       [2]      <---- if we steal [2], we can;t steal [0], [5], [6]
        /   \     /   \
      [3]  [4]   [5]  [6]
  

If we define the node by i, i would be :

                   [i]
                    |     
             +---------------+
             |               |
          [i>L]            [i>R]
            |                |
        +-------+        +-------+          
        |       |        |       |
     [i>L>L] [i>L>R]  [i>R>L] [i>R>R]


Let we split the tree as one connection:

                  [i]            [i]         [i]              [i]                                                          
                   |              |           |                |     
            +-------        +------           ------+          -----+
            |               |                       |               |       
          [i>L]           [i>L]                    [i>R]          [i>R]   
            |               |                       |               |       
        +----               ----+               +----               ----+     
        |                       |               |                       | 
     [i>L>L]                 [i>L>R]        [[i>R>L]                 [i>R>R]       


Is it look similar as list ? we can follow the formula same as [198] and create a new one as following:

    P[i] : profit at houst[i]

    steal at i : P[i]a = (P[i>L>L] +
                          P[i>L>R] +
                          P[i>R>L] +
                          P[i>R>R]) + money at [i] 

    not steal at i : P[i]b = P[i>L] + P[i>R]

    finally, we get : P[i] = max (P[i]a,  P[i]b)


We can finish this formula by recursive:

    int sub_task (TreeNode* root) const {
        if (root == nullptr) {
            return 0;
        } else {
            int v_do = 0;
            int v_notdo = 0;

            if (root->left != nullptr) {
                v_notdo += sub_task(root->left);
                v_do += sub_task(root->left->left);
                v_do += sub_task(root->left->right);
            }
            
            if (root->right != nullptr) {
                v_notdo += sub_task(root->right);
                v_do += sub_task(root->right->left);
                v_do += sub_task(root->right->right);
            }
            
            return std::max(v_notdo, v_do + root->val);
        }
    }


At this step, we finish the problem, but, there is a problem at above source code.
Evenought above source code is accepted, but the running time is terrible, what happened?

The code to process left side will first get value form root->left, and get value form root->left->left and root->left->right, in this step,
When we enter next function call by "sub_task(root->left)", the root->left-left and root->left->right will processed twice and this is the bottleneck of performance .
        
        if (root->left != nullptr) {
            v_notdo += sub_task(root->left);        //  << enter this iteration, it will process root->left->left and root->left->right  
                                                    //
                                                    //  but, at following step, we re-proces  root->left->left and root->left->right again.
                                                    //    
            v_do += sub_task(root->left->left);
            v_do += sub_task(root->left->right);
        }

Think about that, when we process "sub_task(root->left)" finish,  it also means we finish the root->left->left and root->left->right. so we just need to
take value from "sub_task(root->left)" rather than create new task to process "sub_task(root->left->left)" and "sub_task(root->left->left)".

How can we implement it? first, we must return a value,  but, which value need to return? 
Assume we at house[i], when we need value at house[i>L>L], house[i>L>R], house[i>R>L] and house[i>R>R] ? 
  - The time when we steal at houst[i]

All we need to do, is return 2 value:
  - One value returned as max profit at current node.  (profit)
  - One value returned as profit if we don't steal current node. (profit_when_no_steal)


    int sub_task (TreeNode* root, int *profit_when_no_steal) const {
        if (root == nullptr) {
            *profit_when_no_steal = 0;
            return 0;
        } else {
            
            int v_do = 0;
            int v_notdo =0;
            
            int vL_no_steal;
            int vR_no_steal;
            v_notdo += sub_task(root->left, &vL_no_steal);
            v_notdo += sub_task(root->right, &vR_no_steal);
            
            v_do += vL_no_steal;
            v_do += vR_no_steal;
            
            // return std::max(v_notdo, v_do + root->val);
            int profit = std::max(v_notdo, v_do + root->val);
            *profit_when_no_steal = v_notdo;
            return profit;
        }
    }