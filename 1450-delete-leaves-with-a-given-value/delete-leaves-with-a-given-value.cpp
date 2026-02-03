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
    TreeNode* removeLeafNodes(TreeNode* &root, int target) {// we have to add & here to cah ge the original copy
        if(root==NULL) return root;
        if(root->left==NULL && root->right==NULL){
            if(root->val==target){
                root=NULL;
            }
        }

        if(root!=NULL) removeLeafNodes(root->left,target);
        if(root!=NULL) removeLeafNodes(root->right,target);

        if(root!=NULL && root->left==NULL && root->right==NULL){
            if(root->val==target){
                root=NULL;
            }
        }

        return root;

    }
};