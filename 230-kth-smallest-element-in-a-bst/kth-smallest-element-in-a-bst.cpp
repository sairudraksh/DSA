class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return NULL;
        vector<int>v;
        inorder(root,v);
        return v[k-1];
    }
};