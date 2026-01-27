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
    vector<vector<int>>ans;
    void find(TreeNode* root,int curr,int &target,vector<int>&v){
        if(root==NULL) return;

        if(curr==target){
            v.push_back(root->val);
            return;
        }

        find(root->left,curr+1,target,v);
        find(root->right,curr+1,target,v);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return ans;
        int n=levels(root);
        bool straight=true;
        for(int i=1;i<=n;i++){
            vector<int>v;
            find(root,1,i,v);
            if(!straight){
                straight=true;
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            else{
                straight=false;
                ans.push_back(v);
            }
        }
        return ans;
    }
};