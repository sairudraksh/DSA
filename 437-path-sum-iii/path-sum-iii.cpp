// class Solution {
// public:
    // vector<vector<int>>ans;
    // void find(TreeNode* root,int &curr,int &target,vector<int>&v){
    //     if(root==NULL) return ;
    //     if(root->left==NULL && root->right==NULL){
    //         curr+=root->val;
    //         v.push_back(root->val);
    //         if(curr==target){
    //             ans.push_back(v);
    //         }
    //         curr-=root->val;
    //         v.pop_back();
    //         return;
    //     }
    //     curr+=root->val;
    //     v.push_back(root->val);
    //     find(root->left,curr,target,v);
    //     find(root->right,curr,target,v);
    //     curr-=root->val;
    //     v.pop_back();
    // }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         if(root==NULL) return ans;
//         vector<int>v;
//         int curr=0;
//         find(root,curr,targetSum,v);
//         return ans;
//     }
// };
class Solution {
public:
    int count=0;
    void find(TreeNode* root,long long &curr,int &target){
        if(root==NULL) return;
        curr+=root->val;
        if(curr==target){
            count++;
        }
        find(root->left,curr,target);
        find(root->right,curr,target);
        curr-=root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return count;
        long long curr=0;
        find(root,curr,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
    }
};