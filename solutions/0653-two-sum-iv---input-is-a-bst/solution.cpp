/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorder;

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

    bool findTarget(TreeNode* root, int k) {

        dfs(root);

        int i = 0;
        int j = inorder.size() - 1;

        while (i < j) {
            int sum = inorder[i] + inorder[j];

            if (sum == k)
                return true;
            else if (sum < k)
                i++;
            else
                j--;
        }

        return false;
    }
};
