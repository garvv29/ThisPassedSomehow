class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *p1 = dummy, *p2 = dummy;

        for (int i = 0; i <= n; i++) {
            p2 = p2->next;
        }

        while (p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode* temp = p1->next;
        p1->next = p1->next->next;
        delete temp;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

