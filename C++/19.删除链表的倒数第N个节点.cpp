#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};
//单指针遍历
//class Solution {
//public:
//    static ListNode* removeNthFromEnd(ListNode* head, int n) {
//        if(head==nullptr)return nullptr;
//        if(head->next==nullptr&&n==1)return nullptr;
//        ListNode* tmp=head,*tmp_2=head;
//        int nums=1;
//        while(tmp->next->next!=nullptr){++nums;tmp=tmp->next;}
//        if(n==1){tmp->next=nullptr;return head;}
//        ++nums;
//        if(nums==n)
//            return head->next;
//        int xxx=nums-n;
//        while(--xxx>0){
//            tmp_2=tmp_2->next;
//        }
//        ListNode*tmp_3=tmp_2->next;
//        tmp_2->next=tmp_3->next;
//        delete tmp_3;
//        return head;
//    }
//};
//双指针（快慢指针）
//快指针先走n步，然后快慢一起走，直到快指针走到最后
class Solution {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head | !head -> next) return nullptr;
        ListNode * fast = head, *slow = head;
        for(int i = 0; i < n; i++){
            fast = fast -> next;
        }
        if(!fast){
            return head -> next;
        }
        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};

int main() {
    auto* l1=new ListNode(1);
    auto* l2=new ListNode(2);
    auto* l3=new ListNode(3);
    auto* l4=new ListNode(4);
    auto* l5=new ListNode(5);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;
    auto p=Solution::removeNthFromEnd(l1,5);
    while(p->next!=nullptr){
        cout<<p->val<<' ';
        p=p->next;
    }
    cout<<p->val;
    return 0;
}