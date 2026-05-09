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
    bool res;
    int find(TreeNode* root){
        if(root==NULL) return true;
        int left=find(root->left);
        int right=find(root->right);

        if(abs(left-right)>1) res=false;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        res=true;
        int a=find(root);
        return res;
    }
};