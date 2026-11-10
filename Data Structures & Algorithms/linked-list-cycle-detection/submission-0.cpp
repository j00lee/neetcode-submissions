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
    bool hasCycle(ListNode* head) {
        // two pointers
        ListNode* p1 = head;
        ListNode* p2 = head; 

        while (p1 and p2) {
            // move pointers
            p1 = p1->next;
            p2 = p2->next;
            if (!p2) {
                return false;
            } 
            p2 = p2->next;
            if (p1 == p2) {
                return true;
            }
        }
        return false;
    }
};
