#include <iostream>
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static int kthToLast(ListNode* head, int k) {
        auto p = head;

        while(k>0){
            p=p->next;
            --k;
        }
        while(p!= nullptr){
            p=p->next;
            head=head->next;
        }
        return head->val;
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

    std::cout<<Solution::kthToLast(p1, 2);
    return 0;
}
