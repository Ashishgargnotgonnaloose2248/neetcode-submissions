class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length = 0;
        ListNode* temp = head;

        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        // If head is the node to delete
        if(n == length){
            return head->next;
        }

        int position = length - n;

        ListNode* current = head;
        ListNode* prev = NULL;

        // Directly move current to the node to delete
        for(int i = 1; i <= position; i++){
            prev = current;
            current = current->next;
        }

        // Remove current
        prev->next = current->next;

        return head;
    }
};