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
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL) return;

        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* find(vector<int>&v,int l,int r){
        if(l>r) return NULL;

        int mid=(r+l)/2;
        TreeNode* root=new TreeNode(v[mid]);

        root->left=find(v,l,mid-1);
        root->right=find(v,mid+1,r);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        TreeNode* newRoot=find(v,0,v.size()-1);
        return newRoot;
    }
};