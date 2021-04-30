#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static void deleteNode(ListNode *node) {
        auto p = node->next;
        while (p->next != nullptr) {
            node->val = p->val;
            node = node->next;
            p = p->next;
        }
        node->val = p->val;
        node->next = nullptr;
    }
};

int main() {
    auto p1 = new ListNode(7);
    auto p2 = new ListNode(2);
    auto p3 = new ListNode(4);
    auto p4 = new ListNode(3);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    Solution::deleteNode(p3);
    while (p1 != nullptr) {
        cout << p1->val << ' ';
        p1 = p1->next;
    }
    return 0;
}
