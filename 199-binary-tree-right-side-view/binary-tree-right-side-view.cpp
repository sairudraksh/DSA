/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void find(TreeNode* root,int curr,int &target,vector<int>&v){
        if(root==NULL) return;
        if(curr==target){
            v.push_back(root->val);
            return;
        }
        find(root->left,curr+1,target,v);
        find(root->right,curr+1,target,v);
    }
    vector<int> rightSideView(TreeNode* root) {
        int n=levels(root);
        vector<int>ans;
        if(root==NULL) return ans;
        
        for(int i=1;i<=n;i++){
            vector<int>v;
            find(root,1,i,v);
            ans.push_back(v[v.size()-1]);
        }
        return ans;
    }
};