class Solution {
public:
    void preorder(vector<int>&v,TreeNode* root){
        if(root==NULL) return;
        v.push_back(root->val);
        preorder(v,root->left);
        preorder(v,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        preorder(v,root);
        return v;
    }
};