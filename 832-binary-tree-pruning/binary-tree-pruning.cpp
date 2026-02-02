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
    bool contains(TreeNode* root){
        if(root==NULL) return false;
        if(root->val==1) return true;
        return contains(root->left) || contains(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        if(!contains(root->left)){
            root->left=NULL;
        }
        if(!contains(root->right)){
            root->right=NULL;
        }

        pruneTree(root->right);
        pruneTree(root->left);
        if(root->left==NULL && root->right==NULL && root->val==0) return NULL; 
        return root;
    }
};