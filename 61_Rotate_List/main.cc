#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 8 ms, faster than 77.01% of C++ online submissions for Rotate List.
// Memory Usage: 11.8 MB, less than 13.38% of C++ online submissions for Rotate List.


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        } else if (head->next == nullptr) {
            return head;
        } else if (k == 0) {
            return head;
        }

        // create a step every 1023 nodes
        int list_count = 1;
        ListNode *last_node = head;

        std::unordered_map<int , ListNode*> mm;
        mm.emplace(0, head);
        while (last_node->next != nullptr) {
            int sub_count = 0;
            while (!(sub_count & 128) && last_node->next != nullptr) {
                last_node = last_node->next;
                sub_count++;
            }
            list_count += sub_count;
            mm.emplace(list_count, head);
        }

        k = k % list_count;
        if (k == 0) return head;

        int move_count = list_count - k;

        int key = move_count / 127;
        auto iter = mm.find(key);
        move_count %= 127;

        ListNode *prev_head = iter->second;
        while (move_count > 1) {
            prev_head = prev_head->next;
            move_count--;
        }

        last_node->next = head;
        head  = prev_head->next;    // new whead
        prev_head->next = nullptr;

        return head;
    }
};


// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if (head == nullptr) {
//             return head;
//         } else if (head->next == nullptr) {
//             return head;
//         } else if (k == 0) {
//             return head;
//         }


//         int list_count = 1;
//         ListNode *last_node = head;
//         while (last_node->next != nullptr) {
//             last_node = last_node->next;
//             list_count++;
//         }

//         k = k % list_count;
//         if (k == 0) return head;

//         int move_count = list_count - k;

//         ListNode *prev_head = head;
//         while (move_count > 1) {
//             prev_head = prev_head->next;
//             move_count--;
//         }

//         last_node->next = head;
//         head  = prev_head->next;    // new whead
//         prev_head->next = nullptr;

//         return head;
//     }
// };

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
    ListNode *ret = ss.rotateRight(data, 1);
    p = ret;
    while (p != nullptr) {
        printf("%d\n", p->val);
        p = p->next;
    }

    return 0;
}