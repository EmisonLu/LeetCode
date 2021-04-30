#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)return false;

        auto p1 = head, p2 = head->next->next;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1 == p2)return true;
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == nullptr)return false;
            p2 = p2->next;
        }
        return false;
    }
};

int main() {
    auto p1 = new ListNode(1);
    auto p2 = new ListNode(2);
    auto p3 = new ListNode(3);
    auto p4 = new ListNode(4);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p2;

    std::cout << Solution::hasCycle(p1);
    return 0;
}
