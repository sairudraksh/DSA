// class Solution {
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
//     }
// };
class Solution {
public:
    void find(TreeNode* root,vector<int>&v,int curr,int target){
        if(root==NULL) return;
        if(curr==target){
            v.push_back(root->val);
            return;
        }
        find(root->left,v,curr+1,target);
        find(root->right,v,curr+1,target);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v1;
        int n=levels(root);
        if(n==1){
            vector<int>v;
            v.push_back(root->val);
            v1.push_back(v);
            return v1;
        }
        for(int i=n;i>=1;i--){
            vector<int>v;
            find(root,v,1,i);
            v1.push_back(v);
        }
        return v1;
    }
};