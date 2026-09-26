
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = NULL;
        ListNode* current = head;

        while(current != NULL){
            ListNode* next = current->next;

            current->next = previous;

            previous = current;
            current = next;
        }
        return previous;
    }
};
