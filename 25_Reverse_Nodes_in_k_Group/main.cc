#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 16 ms, faster than 83.68% of C++ online submissions for Reverse Nodes in k-Group.
// Memory Usage: 11.6 MB, less than 13.15% of C++ online submissions for Reverse Nodes in k-Group.
// or
// Runtime: 24 ms, faster than 29.48% of C++ online submissions for Reverse Nodes in k-Group.
// Memory Usage: 11.6 MB, less than 13.72% of C++ online submissions for Reverse Nodes in k-Group.


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:

    void revert_list(ListNode **head,
                     int k,
                     ListNode **proc_last) const {
        // C  N
        // 1  2  3  4  5
        // ListNode **cur_head = head;
        ListNode *cur_head = *head;
        ListNode *cur = *head;
        ListNode *cur_next = cur->next;

        while (k > 0) {
            cur->next = cur_next->next;
            cur_next->next = cur_head;
            cur_head = cur_next;
            cur_next = cur->next;
            k--;
            // cur->next = cur_next->next;
            // cur_next->next = (*cur_head);
            // (*cur_head) = cur_next;
            // cur_next = cur->next;
            // k--;
        }
        *head = cur_head;

        *proc_last = cur;
    }

    size_t getCount(ListNode* head) const {
        size_t ret = 0;
        while (head != nullptr) {
            head = head->next;
            ret++;
        }

        return ret;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *proc_last = head;
        k -= 1;
        if (k == 0) return head;

        size_t count_of_list = getCount(head);
        size_t proc_count = (count_of_list) / (k + 1);
        if (proc_count < 1) return head;
        proc_count--;


        revert_list(&head, k, &proc_last);

        while (proc_count >0) {
            revert_list(&proc_last->next, k, &proc_last);
            proc_count--;
        }

        return head;
    }

    void print(ListNode* head) const {
        ListNode *p = head;
        while (p != nullptr) {
            printf("[%d] ", p->val);
            p = p->next;
        }
        printf("\n");
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
    ListNode *ret = ss.reverseKGroup(data, 1);

    printf("Final : \n");
    while (ret != nullptr) {
        printf("[%d] ", ret->val);
        ret = ret->next;
    }
    printf("\n");

    return 0;
}