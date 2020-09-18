#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <unordered_map>
// Runtime: 12 ms, faster than 98.04% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 22.3 MB, less than 5.13% of C++ online submissions for Validate Binary Search Tree.

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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;


        class Bundle {
         public:
            Bundle(TreeNode* node, int64_t parent_min, int64_t parent_max) {
                this->node = node;
                this->parent_max = parent_max;
                this->parent_min = parent_min;
            }
            TreeNode* node;
            int64_t parent_max;
            int64_t parent_min;
        };
        std::queue<Bundle> tester;
        tester.emplace(root, INT64_MIN, INT64_MAX);

            //     5
            //    / \
            //   1   8
            //      / \
            //     3   16
        while (tester.size() > 0) {
            const Bundle &bundle = tester.front();
            const TreeNode *node = bundle.node;
            if (node->val >= bundle.parent_max || node->val <= bundle.parent_min) {
                return false;
            }

            if (node->left != nullptr) {
                tester.emplace(node->left, bundle.parent_min, node->val);
            }

            if (node->right != nullptr) {
                tester.emplace(node->right, node->val, bundle.parent_max);
            }
            tester.pop();
        }
        return true;
    }
};

int main()
{
    TreeNode *data = nullptr;
    TreeNode *p2  = new TreeNode(-2147483648);
    // TreeNode *p1  = new TreeNode(1);
    // TreeNode *p3  = new TreeNode(3);
    data = p2;
    // p2->left = p1;
    // p2->right = p3;
    
   

    Solution ss;
    printf("%d\n ", ss.isValidBST(data));


    return 0;
}