
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* markprev2 = dummy;
        ListNode* curr = head;

        for (int k = 0; k < left-1; k++) {
            markprev2 = markprev2->next;
            curr = curr->next;
        }

        ListNode* mark = curr;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        for (int k = 0; k < (right - left); k++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        markprev2
        mark->next = curr;

        if (left == 1) {
            return prev;
        }
        else {
            head->next = prev;
        }

        return head;
    }
};
