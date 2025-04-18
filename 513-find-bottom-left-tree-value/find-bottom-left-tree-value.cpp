class Solution {
public:
    void bottom(TreeNode* root,int curr,int target,vector<int>&v){
        if(root==NULL) return;
        if(curr==target){
            v.push_back(root->val);
            return;
        }
        bottom(root->left,curr+1,target,v);
        bottom(root->right,curr+1,target,v);
    }
    int level(TreeNode *root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return 0;
        int n=level(root);
        vector<int>v;
        int curr=1;
        bottom(root,curr,n,v);
        return v[0];
    }
};