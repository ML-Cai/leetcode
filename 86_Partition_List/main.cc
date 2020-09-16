#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Partition List.
// Memory Usage: 10.4 MB, less than 12.54% of C++ online submissions for Partition List.
// or
// Runtime: 4 ms, faster than 92.54% of C++ online submissions for Partition List.
// Memory Usage: 10.6 MB, less than 5.23% of C++ online submissions for Partition List.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* head_L = nullptr;
        ListNode* head_R = nullptr;
        ListNode* prev_p_L = nullptr;
        ListNode* prev_p_R = nullptr;
        ListNode* p = nullptr;

        // check head
        if (head->val < x) {
            head_L = head;

            prev_p_R = head;
            while (prev_p_R->next != nullptr && prev_p_R->next->val < x) {
                prev_p_R = prev_p_R->next;
            }
            head_R = prev_p_R->next;
            if (head_R != nullptr) p = head_R->next;
        } else {
            head_R = head;

            prev_p_L = head;
            while (prev_p_L->next != nullptr && prev_p_L->next->val >= x) {
                prev_p_L = prev_p_L->next;
            }
            head_L = prev_p_L->next;
            if (head_L != nullptr) p = head_L->next;
        }

        // check all grather-equal or less ?
        if (head_L == nullptr) {
            return head_R;
        } else if (head_R == nullptr) {
            return head_L;
        }

        // cut prev node
        if (prev_p_L != nullptr && prev_p_L->val >= x) prev_p_L->next = nullptr;
        if (prev_p_R != nullptr && prev_p_R->val < x) prev_p_R->next = nullptr;

        // through remain values
        ListNode* tail_L = prev_p_R;
        ListNode* tail_R = prev_p_L;
        if (tail_L == nullptr) tail_L = head_L;
        if (tail_R == nullptr) tail_R = head_R;

        while (p != nullptr) {
            if (p->val < x) {
                tail_L->next = p;
                tail_L = tail_L->next;
            } else {
                tail_R->next = p;
                tail_R = tail_R->next;
            }
            p = p->next;
        }

        tail_L->next = head_R;
        tail_R->next = nullptr;
        return head_L;
    }
};

int main()
{
    ListNode * data;
    ListNode * p;
    data = new ListNode(1);
    p = data;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(2);

    // data = new ListNode(1);
    // p = data;
    // p->next = new ListNode(2);
    // p = p->next;
    // p->next = new ListNode(3);

    Solution ss;
    ListNode *ret = ss.partition(data, 3);

    while (ret != nullptr) {
        printf("[%d]\n", ret->val);
        ret = ret->next;
    }

 
    return 0;
}