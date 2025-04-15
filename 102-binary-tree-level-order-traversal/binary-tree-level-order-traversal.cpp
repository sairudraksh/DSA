class Solution {
public:
    void ordertraversal(int target,int curr,vector<int>&v,vector<vector<int>>&v1,TreeNode* root){
        if(root==NULL) return;
        if(curr==target){
            v.push_back(root->val);
            return;
        }
        if(curr<target){
            ordertraversal(target,curr+1,v,v1,root->left);
            ordertraversal(target,curr+1,v,v1,root->right);
        }
    }
    int size(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(size(root->left) , size(root->right));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n=size(root);
        vector<vector<int>>v1;
        for(int i=1;i<=n;i++){
            vector<int>v;
            ordertraversal(i,1,v,v1,root);
            v1.push_back(v);
        }
        return v1;
    }
};