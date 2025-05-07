class Solution {
public:
    int finalans=INT_MAX;
    void find(TreeNode* root,int val,int &ans){
        if(root==NULL) return;
        if(root->val>val){
            int min=root->val-val;
            if(min<ans) ans=min;
        }
        if(root->val<val){
            int min=val-root->val;
            if(min<ans) ans=min;
        }
        find(root->left,val,ans);
        find(root->right,val,ans);
    }
    int minDiffInBST(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=INT_MAX;
        find(root,root->val,ans);
        if(ans<finalans){
            finalans=ans;
        }
        minDiffInBST(root->left);
        minDiffInBST(root->right);
        return finalans;
    }
};