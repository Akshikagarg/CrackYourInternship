class Solution {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        if (n == 0 || head == nullptr) {
            return nullptr;
        }

        ListNode *fast = head, *slow = head;

        // Advance fast pointer by n.
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast is nullptr, n is equal to length of list => meaning we need to remove head.
        if (fast == nullptr)
            return head->next;

        // Increment fast and slow by 1 till end of the list
        while (fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *to_del = slow->next;

        // slow in this case points to the node before to-deleted-node.
        slow->next = slow->next ? slow->next->next : nullptr;

        delete to_del;

        return head;
    }
};
