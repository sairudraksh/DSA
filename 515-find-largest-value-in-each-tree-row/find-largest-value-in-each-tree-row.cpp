class Solution {
public:
    void find(TreeNode* root,int curr,int target,int &ans){
        if(root==NULL) return;
        if(curr==target){
            if(root->val>ans){
                ans=root->val;
            }
        }
        find(root->left,curr+1,target,ans);
        find(root->right,curr+1,target,ans);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    vector<int> largestValues(TreeNode* root) {
        int n=levels(root);
        vector<int>v;
        for(int i=1;i<=n;i++){
            int max=INT_MIN;
            int curr=1;
            find(root,curr,i,max);
            v.push_back(max);
        }
        return v;
    }
};