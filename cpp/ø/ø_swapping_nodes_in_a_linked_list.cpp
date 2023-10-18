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
            if (one->next == two) {
                one->next = two->next;
                two->next = one;
            }
            else {
                ListNode* temp = two->next;
                two->next = one->next;
                one->next = temp;
                prev2->next = one;
            }

            return dummy->next;
        }
};

bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> s;
    while (head) {
        if (s.end() != s.find(head)) {
            return true;
        }
        cout << head->val << " ";
        s.insert(head);
        head=head->next;
    }
    cout << '\n';
    return false;
}

void printList(ListNode* head) {
    if (!head) return;
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << '\n';
}

int main() {
    ListNode* body9 = new ListNode(5);
    ListNode* body8 = new ListNode(9, body9);
    ListNode* body7 = new ListNode(0, body8);
    ListNode* body6 = new ListNode(3, body7);
    ListNode* body5 = new ListNode(8, body6);
    ListNode* body4 = new ListNode(7, body5);
    ListNode* body3 = new ListNode(6, body4);
    ListNode* body2 = new ListNode(6, body3);
    ListNode* body1 = new ListNode(9, body2);
    ListNode* head = new ListNode(7, body1);

    // [7, 9, 6, 6, 7, 8, 3, 0, 9, 5]

    Solution test;
    head = test.swapNodes(head, 5);

    if (!hasCycle(head)) printList(head);
    else cout << "has cycle!\n";

    delete head;
    delete body1;
    delete body2;
    delete body3;
    delete body4;
    delete body5;

    return 0;
}
