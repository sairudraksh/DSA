class Solution {
public:
    void postorder(vector<int>&v,TreeNode* root){
        if(root==NULL) return;
        postorder(v,root->left);
        postorder(v,root->right);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        postorder(v,root);
        return v;
        
    }
};