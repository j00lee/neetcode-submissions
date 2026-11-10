class DLNode {
public:
    int key;
    int val;
    DLNode* prev;
    DLNode* next;

    DLNode(int keyy, int vall) {
        key = keyy;
        val = vall;
    }
};


class LRUCache {
private:
    // Use a linked list + hash map
    int capacity;
    DLNode* cache;  // dummy head for the cache
    map<int,DLNode*> nmap;

    // void moveToFront(int key) {
    //     // moves the node containing given key to front

    // }
    void print_list() {
        DLNode* curr = cache->next;
        printf("[");
        while (curr != cache) {
            // print the key and value
            printf("(%d, %d), ", curr->key, curr->val);
            curr = curr->next;
        }
        printf("]\n");
    }

public:
    LRUCache(int capacityy) {
        capacity = capacityy;
        cache = new DLNode(-1, -1);
        cache->next = cache;
        cache->prev = cache;
    }
    
    int get(int key) {
        if (nmap.find(key) == nmap.end()) return -1;
        // remove node from list
        DLNode* node = nmap[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // move the key to front of the linked list
        node->prev = cache->prev;
        node->prev->next = node;
        node->next = cache;
        cache->prev = node;

        printf("get %d\n", key);
        print_list();
        return node->val;
    }
    
    void put(int key, int value) {
        printf("put (%d, %d)\n", key, value);
        if (nmap.find(key) == nmap.end()) {
            // create new key-value node
            DLNode* node = new DLNode(key, value);
            nmap[key] = node;
            // insert node to back of cache
            // cache->prev is current end of list
            // set node->prev = cache->prev
            // node->prev->next = node
            // node->next = cache
            // cache->prev = node
            node->prev = cache->prev;
            node->prev->next = node;
            node->next = cache;
            cache->prev = node;

            if (nmap.size() > capacity) {
                // remove first node from list
                int keyToRemove = cache->next->key;
                cache->next = cache->next->next;
                cache->next->prev = cache;
                nmap.erase(keyToRemove);
            }
        } else {
            // update value for key
            DLNode* nodeToUpdate = nmap[key];
            nodeToUpdate->val = value;
            printf("updated value to: %d\n", nodeToUpdate->val);
            // Remove this node from list
            nodeToUpdate->prev->next = nodeToUpdate->next;
            nodeToUpdate->next->prev = nodeToUpdate->prev;

            // Then insert the node to the back of list
            nodeToUpdate->prev = cache->prev;
            nodeToUpdate->prev->next = nodeToUpdate;
            nodeToUpdate->next = cache;
            cache->prev = nodeToUpdate;
        }
        print_list();
    }
};
