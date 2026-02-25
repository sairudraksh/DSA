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
    void find(TreeNode* root,vector<int>&v,int curr,int &target){
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n=levels(root);
        vector<vector<int>>ans;

        for(int i=1;i<=n;i++){
            vector<int>v;

            find(root,v,1,i);

            ans.push_back(v);
        }
        return ans;

    }
};