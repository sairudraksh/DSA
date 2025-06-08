class Solution {
public:
    void find(TreeNode* root,int curr,int target,long long &min){
        if(root==NULL) return;
        if(min!=LLONG_MIN) return;
        if(curr==target){
            min=root->val;
            return;
        }
        find(root->left,curr+1,target,min);
        if(min!=LLONG_MIN) return;
        find(root->right,curr+1,target,min);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    int findBottomLeftValue(TreeNode* root) {
        int n=levels(root);
        int curr=1;
        long long int ans= LLONG_MIN;
        find(root,curr,n,ans);
        return ans;
    }
};