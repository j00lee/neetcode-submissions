/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // establish copies of next pointers first
        // establish copies of random pointers
        Node* curr = head;
        Node* dummy = new Node(0);
        Node* copy = dummy;
        map<Node*,Node*> oldToNew;
        oldToNew[nullptr] = nullptr;
        while (curr) {
            Node* newNode = new Node(curr->val);
            oldToNew[curr] = newNode;
            copy->next = newNode;
            copy = newNode;
            curr = curr->next;
        }

        // establish copies of random pointers
        curr = head;
        copy = dummy->next;
        while (curr) {
            copy->random = oldToNew[curr->random];
            copy = copy->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};
