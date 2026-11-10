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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode dummy(0);
        ListNode* prev = &dummy;

        while (curr1 or curr2) {
            int val1;
            int val2;
            if (curr1 and curr2) {
                val1 = curr1->val;
                val2 = curr2->val;
                if (val1 < val2) {
                    cerr << "val1: " << val1 << " val2: " << val2 << "\n";
                    prev->next = curr1;
                    prev = curr1;
                    curr1 = curr1->next;
                } else {
                    cerr << "val1: " << val1 << " val2: " << val2 << "\n";
                    prev->next = curr2;
                    prev = curr2;
                    curr2 = curr2->next;
                }
            } else if (curr1) {
                cerr << "curr1 not null\n";
                prev->next = curr1;
                prev = curr1;
                curr1 = curr1->next;
                break;
            } else {
                cerr << "curr2 not null, prev: " << prev->val << "\n";
                prev->next = curr2;
                cerr << "here\n";
                prev = curr2;
                cerr << "there\n";
                curr2 = curr2->next;
                cerr << "where\n";
                break;
            }
        }
        return dummy.next;
    }
};
