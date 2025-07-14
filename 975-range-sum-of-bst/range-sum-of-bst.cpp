class Solution {
public:
    void find(TreeNode* root,int &low,int &high,int &ans){
        if(root==NULL) return;
        if(root->val>=low && root->val<=high){
            ans+=root->val;
        }
        find(root->left,low,high,ans);
        find(root->right,low,high,ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        find(root,low,high,ans);
        return ans;
    }
};