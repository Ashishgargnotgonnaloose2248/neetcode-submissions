class Solution {
public:
    void reorderList(ListNode* head) {

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* current = slow->next;
        ListNode* previous = NULL;

        slow->next = NULL;

        while(current != NULL){
            ListNode* nextnode = current->next;

            current->next = previous;

            previous = current;
            current = nextnode;
        }

        // 3. Merge both halves
        ListNode* first = head;
        ListNode* second = previous;

        while(second != NULL){

            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};