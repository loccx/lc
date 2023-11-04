#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
    ListNode(int x, ListNode* n) : val(x), next(n) {};
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> store;
        ListNode* curr = head;
        while(curr) {
            if (store.find(curr) != store.end()) return curr;
            store.insert(curr);
            curr = curr->next;
        }
        return nullptr;
    }
};

int main() {
    ListNode n3(2);
    ListNode n2(3, &n3);
    ListNode n1(3, &n2);
    n3.next = &n1;

    Solution test;
    ListNode* res = test.detectCycle(&n1);
    if (res) cout << "Value of node that is start of cycle:\n" << test.detectCycle(&n1)->val << '\n';
    else cout << "No cycle detected.\n";
}
