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
    int search(vector<int>& inorder,int left , int right,int val){
        for(int i = left ;i<=right;i++){
            if(inorder[i]== val){
                return i;
            }
            
        }
        return -1;
    }
     TreeNode* helper(vector<int>& postorder, vector<int>& inorder,int& Idx,int left , int right){
        if(left>right) return NULL;
        TreeNode* root = new TreeNode(postorder[Idx]);
        
        int inIdx = search(inorder,left,right,postorder[Idx]);
        Idx--;

        
        root->right =  helper( postorder, inorder, Idx,inIdx+1 ,right);
        root->left = helper( postorder, inorder,Idx,left ,inIdx -1);
        return root;
        




    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int Idx = postorder.size()-1;
     return helper(postorder, inorder,Idx,0, inorder.size()-1);
    }
};
