class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        if (start > end)
            return {NULL};

        vector<TreeNode*> ans;

        for (int root = start; root <= end; root++) {

            vector<TreeNode*> leftTrees = generate(start, root - 1);
            vector<TreeNode*> rightTrees = generate(root + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {

                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;

                    ans.push_back(node);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};
