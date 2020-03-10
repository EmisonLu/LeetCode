#include <iostream>
#include <deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)return head;
        deque<int> deque;
        ListNode *c1=head,*c2;
        int m_c=m,n_c=n,x;
        while(--m_c>0){
            c1=c1->next;
        }
        c2=c1;
        for(int i=0;i<=n-m;++i){
            deque.push_back(c1->val);
            c1=c1->next;
        }
        auto p=deque.end();
        for(int i=0;i<=n-m;++i){
            x=*(--p);
            c2->val=x;
            c2=c2->next;
        }
        return head;
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
    ListNode *r=Solution::reverseBetween(l1,2,5);
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