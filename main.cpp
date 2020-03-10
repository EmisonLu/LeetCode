#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())return nullptr;
        if (lists.size() == 1)return lists[0];
        deque<ListNode*> TT;
        copy(lists.begin(),lists.end(),insert_iterator<deque<ListNode*>>(TT,TT.begin()));
        while(TT.size()>1){
            ListNode *tmp1=TT.front();
            TT.pop_front();
            ListNode *tmp2=TT.front();
            TT.pop_front();
            ListNode *q=mergeTwoLists(tmp1,tmp2);
            TT.push_back(q);
        }
        return TT[0];
    }
private:
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
    while(r->next!= nullptr){
        cout<<r->val;
        tmp=r;
        r=r->next;
        delete tmp;
    }
}
