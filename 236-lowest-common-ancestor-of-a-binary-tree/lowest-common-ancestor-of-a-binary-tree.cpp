/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool exists(TreeNode* root,TreeNode* p){
        if(root==NULL) return false;
        if(root==p) return true;
        return exists(root->left,p) || exists(root->right,p);

    }
    TreeNode* find(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        if((exists(root->left,p) && exists(root->right,q)) || (exists(root->left,q) && exists(root->right,p))) return root;
        else if(exists(root->left,p) && exists(root->left,q)) return find(root->left,p,q);
        else if(exists(root->right,q) && exists(root->right,p)) return find(root->right,p,q);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root,p,q);
    }
};