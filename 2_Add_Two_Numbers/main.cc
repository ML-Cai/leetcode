#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Runtime: 20 ms, faster than 98.39% of C++ online submissions for Add Two Numbers.
// Memory Usage: 70.6 MB, less than 11.47% of C++ online submissions for Add Two Numbers.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * p_l1 = l1;
        ListNode * p_l2 = l2;

        // add L2 to L1
        while (p_l2 != nullptr) {
            p_l1->val += p_l2->val;
            p_l2 = p_l2->next;

            int c = p_l1->val / 10;
            p_l1->val = p_l1->val % 10;

            if (p_l1->next == nullptr) {
                if (p_l2 != nullptr) {
                    // p_l1->next = new ListNode(c);
                    p_l1->next = p_l2;
                    p_l1->next->val +=c;
                    p_l1 = p_l1->next;
                    break;
                } else if (c) {
                    p_l1->next = new ListNode(c);
                    break;
                }
                break;
            } else {
                p_l1->next->val +=c;
            }

            p_l1 = p_l1->next;
        }

        while (p_l1 != nullptr && p_l1->val > 9) {
            p_l1->val -= 10;
            if (p_l1->next == nullptr) {
                p_l1->next = new ListNode(1);
            } else {
                p_l1->next->val +=1;
            }
            p_l1 = p_l1->next;
        }

        return l1;
    }
};


int main()
{
    ListNode *dataA;
    ListNode *dataB;
    ListNode *p;

    // dataA = new ListNode(2);
    // p = dataA;
    // p->next = new ListNode(4);
    // p = p->next;
    // p->next = new ListNode(3);

    // dataB = new ListNode(5);
    // p = dataB;
    // p->next = new ListNode(6);
    // p = p->next;
    // p->next = new ListNode(4);

    //// 18
    // dataA = new ListNode(1);
    // p = dataA;
    // p->next = new ListNode(8);
    
    // dataB = new ListNode(0);
    // p = dataB;
    

    // 1207
    // dataA = new ListNode(2);
    // p = dataA;
    // p->next = new ListNode(4);
    // p = p->next;
    // p->next = new ListNode(3);

    // dataB = new ListNode(5);
    // p = dataB;
    // p->next = new ListNode(6);
    // p = p->next;
    // p->next = new ListNode(8);
    
    // 108
    // dataA = new ListNode(9);
    // p = dataA;
    // p->next = new ListNode(9);
    
    // dataB = new ListNode(9);
    // p = dataB;
        
    // // // 10008
    // dataA = new ListNode(9);
    // p = dataA;
    // p->next = new ListNode(9);
    // p = p->next;
    // p->next = new ListNode(9);
    // p = p->next;
    // p->next = new ListNode(9);
    // p = p->next;
    
    // dataB = new ListNode(9);
    // p = dataB;

    // 10008    
    dataA = new ListNode(9);
    p = dataA;

    dataB = new ListNode(9);
    p = dataB;
    p->next = new ListNode(9);
    p = p->next;
    p->next = new ListNode(9);
    p = p->next;
    p->next = new ListNode(9);
    p = p->next;


    Solution ss;
    ListNode *ret = ss.addTwoNumbers(dataA, dataB);
    printf("fin\n");
    while (ret != nullptr) {
        printf("[%d]\n", ret->val);
        ret = ret->next;
    }

    return 0;
}