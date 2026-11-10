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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // two pointers
        ListNode* p1 = head;
        ListNode* p2 = head;
        for (int i = 0; i <= n; i++) {
            if (!p1) {
                head = head->next;
                return head;
            }
            p1 = p1->next;
        }
        printf("p2: %d\n",p2->val);

        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        printf("p2: %d\n", p2->val);
        if (p2->next) p2->next = p2->next->next;
        return head;
    }
};
