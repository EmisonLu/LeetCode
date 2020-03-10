#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* partition(ListNode* head, int x) {
        if(head==nullptr||head->next==nullptr)return head;
        auto *uou=new ListNode(0),*vov=new ListNode(0);
        ListNode *uou_c=uou,*vov_c=vov;
        while(head!=nullptr){
            if(head->val<x){
                uou_c->next=head;
                uou_c=head;
                head=head->next;
                continue;
            }
            if(head->val>=x){
                vov_c->next=head;
                vov_c=head;
                head=head->next;
                continue;
            }
        }
        vov_c->next=nullptr;
        uou_c->next=vov->next;
        delete vov;
        uou_c=uou->next;
        delete uou;
        return uou_c;
    }
};

int main() {
    auto *l1=new ListNode(1);
    auto *l2=new ListNode(5);
    auto *l3=new ListNode(2);
    auto *q1=new ListNode(4);
    auto *q2=new ListNode(3);
    auto *q3=new ListNode(0);
    auto *q4=new ListNode(5);
    l1->next=l2;
    l2->next=l3;
    l3->next=q1;
    q1->next=q2;
    q2->next=q3;
    q3->next=q4;
    ListNode *r=Solution::partition(l1,3);
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