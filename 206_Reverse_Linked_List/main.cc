#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (head == nullptr) return head;
//         if (head->next == nullptr) return head;

//         ListNode *p = head;

//         while (p->next != nullptr) {
//             ListNode *tmp = head;
//             head = p->next;
//             p->next = head->next;

//             head->next = tmp;
//         }

//         return head;
//     }
// };

// Runtime: 8 ms, faster than 64.98% of C++ online submissions for Reverse Linked List.
// Memory Usage: 8.6 MB, less than 5.02% of C++ online submissions for Reverse Linked List.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;

        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next_head;
        while (cur != nullptr) {
            next_head = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next_head;
        }

        return prev;
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
    ListNode *ret = ss.reverseList(data);
    p = ret;
    while (p != nullptr) {
        printf("%d\n", p->val);
        p = p->next;
    }

    return 0;
}