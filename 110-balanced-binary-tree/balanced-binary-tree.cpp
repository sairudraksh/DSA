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
    int dept(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(dept(root->left),dept(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int left=dept(root->left);
        int right=dept(root->right);

        if(abs(right-left)>=2) return false;

        bool a=isBalanced(root->left);
        bool b=isBalanced(root->right);

        return a && b;
    }
};