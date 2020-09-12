#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 10.9 MB, less than 6.45% of C++ online submissions for Remove Nth Node From End of List.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *p_rm_prev = nullptr;

        while (p != nullptr && n >=0) {
            n--;
            p = p->next;
        }

        if (n == -1) {
            p_rm_prev = head;
        }

        while (p != nullptr) {
            p_rm_prev = p_rm_prev->next;
            p = p->next;
        }

        if (p_rm_prev != nullptr) {
            p_rm_prev->next = p_rm_prev->next->next;
        } else {
            head = head->next;
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
    ListNode *ret = ss.removeNthFromEnd(data, 5);

    while (ret != nullptr) {
        printf("[%d]\n", ret->val);
        ret = ret->next;
    }

    return 0;
}