#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int dfs(TreeNode* n, int& res) {
            if (!n) return 0;

            int left = dfs(n->left, res);
            int right = dfs(n->right, res);

            res = max(res, left + right);
            return max(left, right) + 1;
        }

        int diameterOfBinaryTree(TreeNode* root) {
            int res = 0;
            dfs(root, res);
            return res;
        }
};
