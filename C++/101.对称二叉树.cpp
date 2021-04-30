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
    static bool isSymmetric(TreeNode *root) {
        if (!root)return false;
        return func(root->left, root->right);
    }

    static bool func(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr)return true;
        if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr))return false;
        if (left->val != right->val)return false;
        return func(left->left, right->right) && func(left->right, right->left);
    }
};

int main() {
    auto tree = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                             new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    cout << Solution::isSymmetric(tree);
    return 0;
}
