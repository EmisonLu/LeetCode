#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode sbs(0);
        ListNode *bsb=&sbs;
        bsb->next=head;
        head=head->next;
        while(bsb->next!=nullptr&&bsb->next->next!=nullptr){
            bsb=swap_basic(bsb);
        }
        return head;
    }
private:
    static ListNode* swap_basic(ListNode* oTo){
        ListNode *TTT=oTo->next->next;
        oTo->next->next=TTT->next;
        TTT->next=oTo->next;
        oTo->next=TTT;
        return TTT->next;
    }
};

int main() {
    auto *l1=new ListNode(1);
    auto *l2=new ListNode(3);
    auto *l3=new ListNode(5);
    auto *q1=new ListNode(2);
    l1->next=l2;
    l2->next=l3;
    l3->next=q1;
    ListNode *r=Solution::swapPairs(l1);
    ListNode *tmp;
    while(r->next!= nullptr){
        cout<<r->val;
        tmp=r;
        r=r->next;
        delete tmp;
    }
    cout<<r->val;
    delete r;
    return 0;
}