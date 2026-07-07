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
    void inorder(TreeNode* root , vector<int>& arr){
        if(root == NULL) return;

        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        int i =0,j=0;
        vector<int>arr1;
        vector<int>arr2;
        vector<int>temp;
        inorder(root1,arr1);
        inorder(root2,arr2);

        while(i < arr1.size() &&  j< arr2.size()){
            if(arr1[i]<arr2[j]){
                temp.push_back(arr1[i++]);
            }else{
                temp.push_back(arr2[j++]);
            }
        }
        while(i<arr1.size()){
            temp.push_back(arr1[i++]);
        }
        while(j<arr2.size()){
            temp.push_back(arr2[j++]);
        }

        return temp;
    }
};
