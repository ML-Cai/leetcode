#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <unordered_map>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
                   100
                 25   300
               1           3000
        */
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }
        
        std::queue<TreeNode *> cA;
        std::queue<TreeNode *> cB;
        cA.emplace(p);
        cB.emplace(q);
        
        while(cA.size() > 0) {
            if (cA.size() != cB.size()) {
                return false;
            }
            
            TreeNode *a = cA.front();
            TreeNode *b = cB.front();
            
            if (a != nullptr && b != nullptr) {
                if (a->val == b->val) {
                    cA.emplace(a->left);
                    cA.emplace(a->right);
                    cB.emplace(b->left);
                    cB.emplace(b->right);
                } else {
                    return false;
                }
            } else if (a != nullptr || b != nullptr) {
                return false;
            }
            cA.pop();
            cB.pop();
        }
        return true;
    }
};

int main()
{
    TreeNode *data = nullptr;
    TreeNode *p2  = new TreeNode(5);
    TreeNode *p1  = new TreeNode(1);
    TreeNode *p3  = new TreeNode(30);
    data = p2;
    p2->left = p1;
    p2->right = p3;


    Solution ss;
    printf("%d\n ", ss.isSameTree(data, data));

    return 0;
}