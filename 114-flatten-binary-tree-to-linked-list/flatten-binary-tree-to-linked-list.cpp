class Solution {
public:
    void preorder(vector<TreeNode*>&v,TreeNode* root){
        if(root==NULL) return;
        v.push_back(root);
        preorder(v,root->left);
        preorder(v,root->right);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*>ans;
        preorder(ans,root);
        int n=ans.size();
        for(int i=0;i<n-1;i++){
            ans[i]->right=ans[i+1];
            ans[i]->left=NULL;
        }
        
    }
};