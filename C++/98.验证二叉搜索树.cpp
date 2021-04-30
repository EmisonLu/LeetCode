#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int* last = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root){
            if(!isValidBST(root->left)) return false;
            if (last && *last>=root->val) return false;
            last = &root->val;
            if(!isValidBST(root->right)) return false;
            return true;
        }else return true;
    };
};

int main() {
    auto t1 = new TreeNode(1);
    auto t2 = new TreeNode(3);
    auto t3 = new TreeNode(6);

    auto t4 = new TreeNode(4, t2, t3);
    auto t = new TreeNode(5, t1, t4);
    Solution s;
    cout << s.isValidBST(t);
    return 0;
}
