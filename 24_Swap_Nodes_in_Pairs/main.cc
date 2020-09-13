#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 7.6 MB, less than 24.43% of C++ online submissions for Swap Nodes in Pairs.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        ListNode *cur = head;
        ListNode *prev = nullptr;
        head = head->next;

        // C  N
        // 1  2  3  4  5
        // 2  1  3  4  5
        //
        while (cur != nullptr && cur->next != nullptr) {
            ListNode *tmp = cur->next->next;

            cur->next->next = cur;

            if (prev != nullptr) {
                prev->next = cur->next;
            }
            cur->next = tmp;

            prev = cur;
            cur = cur->next;
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
    // p = p->next;
    // p->next = new ListNode(5);

    Solution ss;
    ListNode *ret = ss.swapPairs(data);

    while (ret != nullptr) {
        printf("[%d]\n", ret->val);
        ret = ret->next;
    }

    return 0;
}