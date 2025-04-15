class Solution {
public:
    void inorder(vector<int>&v,TreeNode* root){
        if(root==NULL) return;
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        inorder(v,root);
        return v;
        
    }
};