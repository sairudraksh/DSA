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
    void find(TreeNode* root,int &ans,int curr,int target){
        if(root==NULL) return;
        if(curr==target){
            if(root->val>ans){
                ans=root->val;
            }
            return;
        }
        find(root->left,ans,curr+1,target);
        find(root->right,ans,curr+1,target);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    vector<int> largestValues(TreeNode* node) {
        vector<int>v;
        if(node==NULL) return v;
        int n=levels(node);
        
        for(int i=1;i<=n;i++){
            int ans=INT_MIN;
            find(node,ans,1,i);
            v.push_back(ans);
        }
        return v;
    }
};