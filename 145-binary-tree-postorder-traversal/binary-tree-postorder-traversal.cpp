class Solution {
public:
    void find(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        find(root->left,v);
        find(root->right,v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        find(root,v);
        return v;
    }
};