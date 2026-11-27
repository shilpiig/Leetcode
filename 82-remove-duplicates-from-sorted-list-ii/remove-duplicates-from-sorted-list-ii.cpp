class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {

            // Check if current value is duplicated
            if (curr->next != nullptr &&
                curr->val == curr->next->val) {

                int duplicate = curr->val;

                // Skip all nodes having this value
                while (curr != nullptr &&
                       curr->val == duplicate) {
                    curr = curr->next;
                }

                // Connect previous distinct node
                prev->next = curr;
            }
            else {
                // Current node is unique
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};