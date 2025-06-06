class Solution {
public:
    void find(TreeNode* root,vector<int>v,vector<vector<int>>&v1,int sum,int targetSum){
        if(root==NULL) return;
        sum=sum+root->val;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                v1.push_back(v);
            }
        }
        find(root->left,v,v1,sum,targetSum);
        find(root->right,v,v1,sum,targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        vector<vector<int>>v1;
        if(root==NULL) return v1;
        int sum=0;
        find(root,v,v1,sum,targetSum);
        return v1;
    }
};