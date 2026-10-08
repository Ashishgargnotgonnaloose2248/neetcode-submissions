
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        int count = 0;

        // Check whether k nodes are available
        while (current != NULL && count < k) {
            current = current->next;
            count++;
        }

        // If fewer than k nodes remain, return as they are
        if (count < k) {
            return head;
        }

        // Reverse the first k nodes
        ListNode* previous = NULL;
        current = head;
        ListNode* nextNode = NULL;
        count = 0;

        while (current != NULL && count < k) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
            count++;
        }

        // Connect the remaining reversed groups
        head->next = reverseKGroup(current, k);

        return previous;
    }
};