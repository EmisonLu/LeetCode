#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        int xXx=head->val;
        auto yYy=head->next,tTt=head;
        while(yYy!=nullptr){
            if(yYy->val==xXx){tTt->next=yYy->next;yYy=yYy->next;}
            else{
                xXx=yYy->val;
                tTt=tTt->next;
                yYy=yYy->next;
            }
        }
        return head;
    }
};

int main() {
    auto *l1=new ListNode(1);
    auto *l2=new ListNode(1);
    auto *l3=new ListNode(1);
    auto *q1=new ListNode(2);
    auto *q2=new ListNode(3);
    auto *q3=new ListNode(4);
    auto *q4=new ListNode(5);
    l1->next=l2;
    l2->next=l3;
    l3->next=q1;
    q1->next=q2;
    q2->next=q3;
    q3->next=q4;
    ListNode *r=Solution::deleteDuplicates(l1);
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