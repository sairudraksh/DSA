class Solution {
public:
    void path(TreeNode* root,vector<vector<int>>&ans,vector<int>v,int currsum,int target){
        if(root==NULL) return;
        currsum=currsum+root->val;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(currsum==target) ans.push_back(v);
            return;
        }
        path(root->left,ans,v,currsum,target);
        path(root->right,ans,v,currsum,target);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        int currsum=0;
        path(root,ans,v,currsum,targetSum);
        return ans;
    }
};