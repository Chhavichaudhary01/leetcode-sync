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

    struct NodeValue {
        int minNode;
        int maxNode;
        int sum;

        NodeValue(int mn, int mx, int s) {
            minNode = mn;
            maxNode = mx;
            sum = s;
        }
    };

    int ans = 0;

    NodeValue solve(TreeNode* root) {

        if (root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = solve(root->left);
        auto right = solve(root->right);

        // Valid BST
        if (left.maxNode < root->val && root->val < right.minNode) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        // Invalid BST
        return NodeValue(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {

        solve(root);

        return ans;
    }
};
