#include <iostream>
#include <map>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size_l1=1,size_l2=1;
        const ListNode *a=l1;
        const ListNode *b=l2;
        while(a->next!=nullptr){size_l1++;a=a->next;}
        while(b->next!=nullptr){size_l2++;b=b->next;}
//        cout<<size_l1<<' '<<size_l2;
        int size_l1_c=size_l1,size_l2_c=size_l2;
        map<int,ListNode*> l1_map,l2_map;
        for (int i = 0; i < size_l1; i++) {
            l1_map.insert(pair<int, ListNode *>(i,l1));
            l1=l1->next;
        }
        for (int i = 0; i < size_l2; i++) {
            l2_map.insert(pair<int, ListNode *>(i,l2));
            l2=l2->next;
        }
        int sum=0,q=1,i;
        for(i=0;size_l1_c>0&&size_l2_c>0;++i){
            sum+=q*(l1_map[i]->val+l2_map[i]->val);
            q*=10;
            --size_l1_c;
            --size_l2_c;
        }
        while(size_l1_c>0){
            sum+=q*l1_map[i]->val;
            ++i;
            q*=10;
            --size_l1_c;
        }
        while(size_l2_c>0){
            sum+=q*l2_map[i]->val;
            ++i;
            q*=10;
            --size_l2_c;
        }
        cout<<sum;
    }
};
int main(){
    ListNode x1(4),x2(3),x3(2);
    ListNode *y1=&x1,*y2=&x2,*y3=&x3;
    y1->next=y2;
    y2->next=y3;
    ListNode z1(5),z2(3),z3(2);
    ListNode *q1=&z1,*q2=&z2,*q3=&z3;
    q1->next=q2;
    q2->next=q3;
    Solution s;
    s.addTwoNumbers(y1,q1);
}

//#include <iostream>
//#include <map>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    explicit ListNode(int x) : val(x), next(nullptr) {}
//};
//
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        // pst中存储表头
//        ListNode  *pst;
//        pst = l1;
//        // 直接将答案存储在l1中，las处理进位
//        l1 -> val += l2 -> val;
//        int las = l1 -> val / 10;
//        l1 -> val %= 10;
//        // l1和l2均为非空时的情况处理
//        while(l1 -> next != NULL && l2 -> next != NULL)
//        {
//            l1 = l1 -> next;
//            l2 = l2 -> next;
//            l1 -> val += l2 -> val + las;
//            las = l1 -> val / 10;
//            l1 -> val %= 10;
//        }
//        // l1空而l2非空时的情况处理
//        while(l2 -> next != NULL)
//        {
//            l2 = l2 -> next;
//            l1 -> next = new ListNode(l2 -> val + las);
//            l1 = l1 -> next;
//            las = l1 -> val / 10;
//            l1 -> val %= 10;
//        }
//        // 可以同时处理l1非空而l2空，以及最后las中需要进位的情况处理
//        while(las > 0)
//        {
//            if(l1 -> next == NULL) l1 -> next = new ListNode(las);
//            else l1 -> next -> val += las;
//            l1 = l1 -> next;
//            las = l1 -> val / 10;
//            l1 -> val %= 10;
//        }
//        return pst;
//    }
//};
//int main(){
//    ListNode x1(4),x2(3),x3(2);
//    ListNode *y1=&x1,*y2=&x2,*y3=&x3;
//    y1->next=y2;
//    y2->next=y3;
//    ListNode z1(5),z2(3),z3(2);
//    ListNode *q1=&z1,*q2=&z2,*q3=&z3;
//    q1->next=q2;
//    q2->next=q3;
//    Solution s;
//    ListNode *h=s.addTwoNumbers(y1,q1);
//    cout<<h->val;
//    return 0;
//}
