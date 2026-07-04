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
    TreeNode* solve(vector<int>& nums, int low, int high) {
        // Base Case
        if (low > high)
            return NULL;

        // Middle element
        int mid = low + (high - low) / 2;

        // Create root
        TreeNode* root = new TreeNode(nums[mid]);

        // Left subtree
        root->left = solve(nums, low, mid - 1);

        // Right subtree
        root->right = solve(nums, mid + 1, high);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};
