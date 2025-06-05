class Solution {
public: 
    void find(TreeNode* root,vector<int>&v){
        if(root==NULL) return ;
        find(root->left,v);
        v.push_back(root->val);
        find(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        find(root,v);
        return v;
    }
};