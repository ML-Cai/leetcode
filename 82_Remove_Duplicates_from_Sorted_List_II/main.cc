#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 8 ms, faster than 93.47% of C++ online submissions for Remove Duplicates from Sorted List II.
// Memory Usage: 11.4 MB, less than 14.72% of C++ online submissions for Remove Duplicates from Sorted List II.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }


        ListNode *check_p = head;
        ListNode *p = head->next;
        ListNode *last_valid = nullptr;
        head = nullptr;

        // 1->1->2->2->3->3->4->4->5
        while (p != nullptr) {
            if (check_p->val != p->val) {
                if (check_p->next == p) {   // just one step between check_p and p ?
                    if (head != nullptr) {
                        last_valid->next = check_p;
                        last_valid = last_valid->next;
                    } else {
                        head = check_p;
                        last_valid = check_p;
                    }
                }
                check_p = p;
            }
            p = p->next;
        }

        if (check_p->next == p) {
            if (head == nullptr) {
                head = check_p;
                check_p->next = nullptr;
            } else {
                last_valid->next = check_p;
                check_p->next = nullptr;
            }
        } else if (last_valid != nullptr) {
            last_valid->next = nullptr;
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
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);

    Solution ss;
    p = ss.deleteDuplicates(data);

    while (p != nullptr) {
        printf("%d\n", p->val);
        p = p->next;
    }
 
    return 0;
}