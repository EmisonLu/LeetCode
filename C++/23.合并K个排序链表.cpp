#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1== nullptr)
            return l2;
        if(l2== nullptr)
            return l1;
        vector<int> tmp;
        ListNode *l1_c=l1,*l2_c=l2;
        while(l1_c->next!= nullptr){
            tmp.push_back(l1_c->val);
            l1_c=l1_c->next;
        }
        tmp.push_back(l1_c->val);
        l1_c->next=l2;
        while(l2_c->next!= nullptr){
            tmp.push_back(l2_c->val);
            l2_c=l2_c->next;
        }
        tmp.push_back(l2_c->val);
        sort(tmp.begin(),tmp.end());
        ListNode *x=l1;
        for(int i=0;i<tmp.size();++i){
            x->val=tmp[i];
            x=x->next;
        }
        return l1;
    }
};

int main() {
    auto *l1=new ListNode(1);
    auto *l2=new ListNode(3);
    auto *l3=new ListNode(5);
    auto *q1=new ListNode(2);
    auto *q2=new ListNode(4);
    ListNode *tmp;
    l1->next=l2;
    l2->next=l3;
    q1->next=q2;
    ListNode *r=Solution::mergeTwoLists(l1,q1);
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