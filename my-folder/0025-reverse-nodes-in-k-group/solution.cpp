class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (k--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;
        ListNode* groupStart = head;

        while (true) {
            ListNode* node = groupStart;
            int count = 0;
            while (node && count < k) {
                node = node->next;
                count++;
            }
            if (count < k) break;
            ListNode* nextGroupStart = node;
            ListNode* newGroupHead = reverse(groupStart, k);
            prevGroupEnd->next = newGroupHead;
            groupStart->next = nextGroupStart;
            prevGroupEnd = groupStart;
            groupStart = nextGroupStart;
        }

        return dummy.next;
    }
};

