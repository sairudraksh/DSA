class Solution {
public:
    void find(TreeNode* root,int &ans,int curr,int &target){
        if(root==NULL) return;
        if(curr==target){
            ans+=root->val;
            return;
        }
        find(root->left,ans,curr+1,target);
        find(root->right,ans,curr+1,target);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    int maxLevelSum(TreeNode* root) {
        int n=levels(root);
        int maxans=INT_MIN;
        int ansidx=0;
        for(int i=1;i<=n;i++){
            int ans=0;
            find(root,ans,1,i);
            if(ans>maxans){
                maxans=ans;
                ansidx=i;
            }
        }
        return ansidx;
    }
};