class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* p1 = head;
        ListNode* p2 = head->next;

        while (p1 && p2) {
            std::swap(p1->val, p2->val);

            p1 = p2->next;
            if (p1) p2 = p1->next;
        }

        return head;
    }
};

