class Solution {
public:
    int maxi=INT_MIN;
    int find(TreeNode* root,int ans){
        if(root==NULL) return 0;
        if(root->val!=ans) return 0;
        return 1+max(find(root->left,ans),find(root->right,ans));
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        int a=find(root->left,root->val);
        int b=find(root->right,root->val);
        maxi=max({maxi,a+b});
        longestUnivaluePath(root->left);
        longestUnivaluePath(root->right);
        return maxi;
    }
};