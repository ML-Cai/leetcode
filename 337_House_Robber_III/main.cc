#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <unordered_map>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    
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
    
    int rob(TreeNode* root) {
        /**
        
                          [i]
                     
                    [i+1]L     [i+1]R
        
               do : [i] = ([i+1]L-L +
                           [i+1]L-R +
                           [i+1]R-L +
                           [i+1]R-R) + [i] 
            no do : [i] = [i+1]L + [i+1]R
        */
        int profit_when_no_steal;
        return this->sub_task(root, &profit_when_no_steal);
    }
};

/**
 * 
 * 
                  [i]            [i]              [i]                                                                      
                   |              |               |           
            +-------       +-------               --------+                                                                   
            |              |                              |                                                         
          [i>L]           [i>L]                           [i>R]                                                          
            |               |                             |                                                          
        +----               ----+                      +---                                                                                                                                   
        |                       |                      |    
     [i>L>L]                 [i>L>R]               [[i>R>L] [i>R>R]                                                                  
 * 
*/

// bad soultion, due to recalculate node 4 times.
// class Solution {
// public:
    
//     int sub_task (TreeNode* root) const {
//         if (root == nullptr) {
//             return 0;
//         } else {
            
//             int v_do = 0;
//             int v_notdo = 0;
            
            
//             if (root->left != nullptr) {
//                 v_notdo += sub_task(root->left);
//                 v_do += sub_task(root->left->left);
//                 v_do += sub_task(root->left->right);
//             }
            
//             if (root->right != nullptr) {
//                 v_notdo += sub_task(root->right);
//                 v_do += sub_task(root->right->left);
//                 v_do += sub_task(root->right->right);
//             }
            
//             return std::max(v_notdo, v_do + root->val);
//         }
//     }
    
//     int rob(TreeNode* root) {
        
//         /**
        
//                           [i]
                     
//                     [i+1]L     [i+1]R
        
//                do : [i] = ([i+1]L-L +
//                            [i+1]L-R +
//                            [i+1]R-L +
//                            [i+1]R-R) + [i] 
//             no do : [i] = [i+1]L + [i+1]R
//         */
        
//         return this->sub_task(root);
//     }
// };


int main()
{
    std::vector<int> data;
    data.emplace_back(7);
    data.emplace_back(1);
    data.emplace_back(5);
    data.emplace_back(3);
    data.emplace_back(6);
    data.emplace_back(4);

    Solution ss;
    printf("%d\n ", ss.rob(data));

    return 0;
}
