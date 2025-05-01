class Solution {
public: 
    int ans=INT_MIN;
    void find(TreeNode* root,int max){
        if(root==NULL) return;
        int k=0;
        if(root->val>=max){
            k=root->val-max;
        }
        else k=max-root->val;
        if(k>ans) ans=k;
        find(root->left,max);
        find(root->right,max);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        int max=root->val;
        find(root,max);
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        return ans;
    }
};