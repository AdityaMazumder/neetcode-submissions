class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        // Check whether k nodes exist
        for(int i = 0; i < k; i++) {
            if(temp == NULL) return head;
            temp = temp->next;
        }

        // Reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;

        for(int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Connect remaining groups
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};