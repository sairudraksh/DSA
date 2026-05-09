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
    int res=INT_MIN;
    int find(TreeNode* root){
        if(root==NULL) return 0;

        int left=max(0,find(root->left));
        int right=max(0,find(root->right));

        res=max(res,left+right+root->val);

        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int a=find(root);

        return res;
    }
};