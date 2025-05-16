class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to simplify edge cases
        ListNode dummy;
        ListNode* curr = &dummy;

        // Pointers to traverse the lists
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                curr->next = p1;
                p1 = p1->next;
            } else {
                curr->next = p2;
                p2 = p2->next;
            }
            curr = curr->next;
        }

        // Append remaining nodes
        curr->next = (p1 != nullptr) ? p1 : p2;

        return dummy.next;
    }
};

