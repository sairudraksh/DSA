class Solution {
public:
    vector<vector<int>>ans;
    void find(TreeNode* root,int &targetSum,vector<int>v,int sum){
        if(root==NULL) return;
        sum+=root->val;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum)ans.push_back(v);
            return;
        }

        find(root->left,targetSum,v,sum);
        find(root->right,targetSum,v,sum);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;

        find(root,targetSum,v,0);
        return ans;
    }
};