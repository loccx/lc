#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* swapNodes(ListNode* head, int k) {
            k--;
            if (head == nullptr) return nullptr;

            ListNode* dummy = new ListNode(0, head);
            ListNode* prev = dummy;
            ListNode* curr = head;

            for (int x = 0; x < k; x++) {
                prev=prev->next;
                curr=curr->next;
            }

            ListNode* one = curr;

            ListNode* prev2 = dummy;
            ListNode* two = head;

            while (curr && curr->next != nullptr) {
                prev2=prev2->next;
                two=two->next;
                curr=curr->next;
            }

            prev->next = two;
            ListNode* temp = one->next;
            one->next = two->next;
            two->next = temp;
            prev2->next = one;

            while (dummy) {
                cout << dummy->val << " ";
                dummy = dummy->next;
            }
            cout << '\n';

            return dummy->next;
        }

};

bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> s;
    while (head) {
        if (s.end() != s.find(head)) {
            return true;
        }
        s.insert(head);
        head=head->next;
    }
    return false;
}

void printList(ListNode* head) {
    if (!head) return;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << '\n';
}

int main() {
    ListNode* body5 = new ListNode(7);
    ListNode* body4 = new ListNode(6, body5);
    ListNode* body3 = new ListNode(4, body4);
    ListNode* body2 = new ListNode(3, body3);
    ListNode* body1 = new ListNode(2, body2);
    ListNode* head = new ListNode(1, body1);

    Solution test;
    head = test.swapNodes(head, 2);

    if (!hasCycle(head)) printList(head);
    else cout << "has cycle!\n";

    delete head;
    delete body1;
    delete body2;
    delete body3;
    delete body4;
    delete body5;
}
