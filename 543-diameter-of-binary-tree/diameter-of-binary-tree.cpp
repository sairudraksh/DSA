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
    int res=0;
    int find(TreeNode* root){
        if(root==NULL) return 0;

        int l=find(root->left);
        int r=find(root->right);

        res=max(res,l+r);

        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        find(root);
        return res;
    }
};