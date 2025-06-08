class Solution {
public:
    void find(TreeNode* root,int curr,int target,int &ans){
        if(root==NULL) return;
        if(curr==target) ans=root->val;
        find(root->left,curr+1,target,ans);
        find(root->right,curr+1,target,ans);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    vector<int> rightSideView(TreeNode* root) {
        int n=levels(root);
        vector<int>v;
        if(root==NULL) return v;
        for(int i=1;i<=n;i++){
            int ans=0;
            int curr=1;
            find(root,curr,i,ans);
            v.push_back(ans);
        }
        return v;
    }
};