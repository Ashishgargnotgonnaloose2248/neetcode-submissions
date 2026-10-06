class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        while(list1 != NULL && list2 != NULL) {

            if(list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }

        if(list1 != NULL) {
            current->next = list1;
        }
        else {
            current->next = list2;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0) {
            return NULL;
        }

        while(lists.size() > 1) {

            vector<ListNode*> newLists;

            for(int i = 0; i < lists.size(); i += 2) {

                ListNode* list1 = lists[i];

                ListNode* list2 = NULL;

                if(i + 1 < lists.size()) {
                    list2 = lists[i + 1];
                }

                newLists.push_back(mergeTwoLists(list1, list2));
            }

            lists = newLists;
        }

        return lists[0];
    }
};