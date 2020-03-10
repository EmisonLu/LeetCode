#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)return head;
        if(k==0)return head;
        auto TvT=head,VtV=head;
        int size=1;
        while(TvT->next!=nullptr){TvT=TvT->next;++size;}
        int real=k%size;
        for(int i=0;i<size-real-1;++i)VtV=VtV->next;
        ListNode sbs(0);
        ListNode *bsb=&sbs;
        bsb->next=head;
        TvT->next=bsb->next;
        bsb->next=VtV->next;
        VtV->next=nullptr;
        return bsb->next;
    }
};

int main() {
    auto *l1=new ListNode(1);
    auto *l2=new ListNode(2);
    auto *l3=new ListNode(3);
//    auto *q1=new ListNode(2);
    l1->next=l2;
    l2->next=l3;
//    l3->next=q1;
    ListNode *r=Solution::rotateRight(l1,1);
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