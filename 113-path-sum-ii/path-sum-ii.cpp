// class Solution {
// public:
//     bool find(TreeNode* root,int curr,int &target){
//         if(root==NULL) return false;
//         if(root->left==NULL && root->right==NULL){
//             curr+=root->val;
//             if(curr==target) return true;
//             return false;
//         }
//         return find(root->left,curr+root->val,target) ||  find(root->right,curr+root->val,target);
//     }
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if(root==NULL) return false;
//         return find(root,0,targetSum);
//     }
// };
class Solution {
public:
    vector<vector<int>>ans;
    void find(TreeNode* root,int &curr,int &target,vector<int>&v){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            curr+=root->val;
            v.push_back(root->val);
            if(curr==target){
                ans.push_back(v);
            }
            curr-=root->val;
            v.pop_back();
            return;
        }

        curr+=root->val;
        v.push_back(root->val);
        find(root->left,curr,target,v);
        find(root->right,curr,target,v);
        curr-=root->val;
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return ans;
        vector<int>v;
        int curr=0;
        find(root,curr,targetSum,v);
        return ans;
    }
};