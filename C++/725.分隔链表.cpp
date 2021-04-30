#include <iostream>
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static vector<ListNode *> splitListToParts(ListNode *root, int k) {
        vector<ListNode *> res;

        int i(0);
        auto head(root);
        while (head != nullptr) {
            ++i;
            head = head->next;
        }
        int n = int(i / k) + 1;
        int s = i - k * n + k;
        ListNode *p;
        for (int j = 0; j < s; ++j) {
            if (root == nullptr) {
                res.emplace_back(nullptr);
            } else {
                p = root;
                for (int a = 0; a < n - 1; ++a) {
                    if (p == nullptr)break;
                    p=p->next;
                }
                res.emplace_back(root);
                if (p == nullptr) {
                    root = nullptr;
                    continue;
                }
                root = p->next;
                p->next = nullptr;
            }
        }
        for (int j = 0; j < k - s; ++j) {
            if (root == nullptr) {
                res.emplace_back(nullptr);
            } else {
                p = root;
                for (int a = 0; a < n - 2; ++a) {
                    if (p == nullptr)break;
                    p=p->next;
                }
                res.emplace_back(root);
                if (p == nullptr) {
                    root = nullptr;
                    continue;
                }
                root = p->next;
                p->next = nullptr;
            }
        }
        return res;
    }
};

int main() {
    auto p1 = new ListNode(1);
    auto p2 = new ListNode(2);
    auto p3 = new ListNode(3);
    auto p4 = new ListNode(4);
    auto p5 = new ListNode(5);
    auto p6 = new ListNode(6);
    auto p7 = new ListNode(7);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;


    auto vec = Solution::splitListToParts(p1, 2);
    for (auto &p : vec) {
        if (p != nullptr) {
            auto a = p;
            while (a != nullptr) {
                cout << a->val << ' ';
                a = a->next;
            }
            cout << endl;
        }
    }
    return 0;
}
