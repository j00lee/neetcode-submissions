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
    void reorderList(ListNode* head) {
        // Reverse the pointers of second half of linked list
        // Start from the two heads
        // Insert nodes from second half in between those from first half

        // Step 1: Find middle of list
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }

        cerr << "Made it past first loop\n";

        int mid = count/2;
        ListNode* midNode = head;
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        cerr << "Middle node is: " << midNode->val << "\n";

        // Step 2: Reverse the second half
        curr = midNode->next;
        ListNode* prev = midNode->next = nullptr;
        ListNode* temp;
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        cerr << "Made it past reverse loop\n";

        // Step 3: Merge
        ListNode* last = prev;
        ListNode* first = head;
        while (last) {
            // Insert last after first
            temp = last->next;
            last->next = first->next;
            first->next = last;
            first = last->next; 
            last = temp;
        }

        cerr << "Made it past merge loop\n";
    }
};
