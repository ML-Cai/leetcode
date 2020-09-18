#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II.
// Memory Usage: 7.8 MB, less than 5.18% of C++ online submissions for Reverse Linked List II.
// or 
// Runtime: 4 ms, faster than 60.82% of C++ online submissions for Reverse Linked List II.
// Memory Usage: 7.9 MB, less than 5.18% of C++ online submissions for Reverse Linked List II.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr || (m == n)) {
            return head;
        }
        n = n - m;
        ListNode *last_valid = nullptr;
        ListNode *p = head;

        while (m >1 && p->next != nullptr) {
            m--;
            last_valid = p;
            p = p->next;
        }
        if (p->next == nullptr) {
            return head;
        }

        // 1->[2]->3->4->5->NULL
        ListNode *revert_head = p;

        while (n >0 && p->next != nullptr) {
            ListNode *cur_next_p = p->next;

            // rev_head
            //  p  --> cur_next_p ---> ?
            p->next = cur_next_p->next;
            cur_next_p->next = revert_head;
            revert_head = cur_next_p;
            n--;
        }

        if (last_valid == nullptr) {
            head = revert_head;
        } else {
            last_valid->next = revert_head;
        }

        return head;
    }
};


int main()
{
    ListNode *data;
    ListNode *p;

    data = new ListNode(1);
    p = data;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);

    Solution ss;
    ListNode *ret = ss.reverseBetween(data, 1, 4);
    p = ret;
    while (p != nullptr) {
        printf("%d\n", p->val);
        p = p->next;
    }

    return 0;
}