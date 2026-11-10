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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // start from ends of both lists
        // add nodes together, create a node and carry over remaining sum
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        ListNode* addend1 = l1;
        ListNode* addend2 = l2;
        int carryover = 0;
        while (addend1 or addend2 or carryover != 0) {
            printf("carryover: %d\n", carryover);
            if (!addend1 and !addend2) {
                curr->next = new ListNode(carryover);
                carryover = 0;
            } else if (!addend1) {
                int sum = addend2->val+carryover;
                carryover = (sum - (sum % 10)) / 10;
                ListNode* digit = new ListNode(sum % 10);
                curr->next = digit;

                addend2 = addend2->next;
            } else if (!addend2) {
                int sum = addend1->val+carryover;
                carryover = (sum - (sum % 10)) / 10;
                ListNode* digit = new ListNode(sum % 10);
                curr->next = digit;
                
                addend1 = addend1->next;
            } else {
                int sum = addend1->val+addend2->val+carryover; 
                carryover = (sum - (sum % 10)) / 10;
                ListNode* digit = new ListNode(sum % 10);
                curr->next = digit;

                addend1 = addend1->next;
                addend2 = addend2->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};
