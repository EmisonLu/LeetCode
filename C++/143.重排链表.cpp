#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)return;
        auto p1 = head, p2 = head;
        while (p2 != nullptr && p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        auto tail = reverse(p1);
        ListNode *a1 = head;
        ListNode *a2 = tail;

        while (true) {
            a1 = head->next;
            head->next = tail;
            a2 = tail->next;
            tail->next = a1;
            head = a1;
            tail = a2;
            if (tail == p1)break;
        }
    }

    static ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr)return nullptr;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        ListNode *p3;

        head->next = nullptr;

        while (p2 != nullptr) {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};

int main() {
    auto p1 = new ListNode(1);
    auto p2 = new ListNode(2);
    auto p3 = new ListNode(3);
    auto p4 = new ListNode(4);
    auto p5 = new ListNode(5);
//    auto p6 = new ListNode(6);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
//    p5->next = p6;

    Solution::reorderList(p1);
    while (p1 != nullptr) {
        cout << p1->val << ' ';
        p1 = p1->next;
    }
    return 0;
}
