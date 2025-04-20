class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void find(TreeNode* root,int curr,int target,vector<int>&v){
        if(root==NULL) return;
        if(curr==target){
            v.push_back(root->val);
            return;
        }
        find(root->left,curr+1,target,v);
        find(root->right,curr+1,target,v);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n=levels(root);
        vector<vector<int>>v1;
        if(root==NULL) return v1;
        int curr=1;
        for(int i=n;i>0;i--){
            vector<int>v;
            find(root,curr,i,v);
            v1.push_back(v);
        }
        return v1;
    }
};