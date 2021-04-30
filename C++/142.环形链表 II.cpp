#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)return nullptr;

        auto p1 = head, p2 = head->next->next;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1 == p2)break;
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == nullptr)return nullptr;
            p2 = p2->next;
        }
        if (p1 == nullptr || p2 == nullptr)
            return nullptr;

        p1=p1->next;
        int cycle(1);
        while(p1!=p2){
            cycle++;
            p1=p1->next;
        }
        auto p3=head;
        while(cycle>0){
            p3=p3->next;
            --cycle;
        }
        while(head!=p3){
            head=head->next;
            p3=p3->next;
        }
        return head;
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
    p4->next = p3;

    auto p = Solution::detectCycle(p1);
    if (p != nullptr)std::cout << p->val;
    return 0;
}
