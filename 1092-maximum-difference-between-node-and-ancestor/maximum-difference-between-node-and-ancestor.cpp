class Solution {
public:
    int maxans=0;
    void find(TreeNode* root,int ans){
        if(root==NULL) return;
        if(root->val>=ans){
            int k=root->val-ans;
            maxans=max(k,maxans);
        }
        else if(root->val<ans){
            int k=ans-root->val;
            maxans=max(k,maxans);
        }
        find(root->left,ans);
        find(root->right,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        find(root,root->val);
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        return maxans;
        
    }
};