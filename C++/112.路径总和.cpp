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
    static bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)return false;
        if (targetSum == root->val && root->right == nullptr && root->left == nullptr)return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

int main() {
    auto tree = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr),
                             new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr, new TreeNode(1))));
    cout << Solution::hasPathSum(tree, 22);
    return 0;
}
