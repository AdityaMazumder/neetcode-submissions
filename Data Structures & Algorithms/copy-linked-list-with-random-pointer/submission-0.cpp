
class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* temp = head;

        // Step 1: Create copies
        while(temp != NULL) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // Step 2: Connect pointers
        temp = head;

        while(temp != NULL) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];

            temp = temp->next;
        }

        // Step 3: Return copied head
        return mp[head];
    }
};
