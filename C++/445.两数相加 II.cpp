#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        stack<int> s1;
        stack<int> s2;

        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *head(nullptr);
        int up(0), sum(0);
        while (!s1.empty() && !s2.empty()) {
            sum = s1.top() + s2.top() + up;
            up = 0;
            if (sum >= 10) {
                up = 1;
                sum = sum - 10;
            }
            auto p = new ListNode(sum);
            p->next = head;
            head = p;
            s1.pop();
            s2.pop();
        }
        if (s1.empty() && s2.empty() && up == 1) {
            auto p = new ListNode(1);
            p->next = head;
            return p;
        }
        while (!s1.empty()) {
            sum = s1.top() + up;
            up = 0;
            if (sum >= 10) {
                up = 1;
                sum = sum - 10;
            }
            auto p = new ListNode(sum);
            p->next = head;
            head = p;
            s1.pop();
        }
        while (!s2.empty()) {
            sum = s2.top() + up;
            up = 0;
            if (sum >= 10) {
                up = 1;
                sum = sum - 10;
            }
            auto p = new ListNode(sum);
            p->next = head;
            head = p;
            s2.pop();
        }
        if(up==1){
            auto p = new ListNode(1);
            p->next = head;
            head=p;
        }
        return head;
    }
};

int main() {
    auto p1 = new ListNode(7);
    auto p2 = new ListNode(2);
    auto p3 = new ListNode(4);
    auto p4 = new ListNode(3);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    auto b1 = new ListNode(5);
    auto b2 = new ListNode(6);
    auto b3 = new ListNode(4);
    b1->next = b2;
    b2->next = b3;

    auto p = Solution::addTwoNumbers(p1, b1);
    while (p != nullptr) {
        cout << p->val << ' ';
        p = p->next;
    }

    return 0;
}
