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
    int findDepth(TreeNode* root){
        if(root==NULL) return 0;

        return 1+max(findDepth(root->left),findDepth(root->right));
    }
    bool find(TreeNode* root){
        if(root==NULL) return true;

        int dept1=findDepth(root->left);
        int dept2=findDepth(root->right);
        if(abs(dept2-dept1)>1) return false;

        bool a=find(root->left);
        bool b=find(root->right);

        return a && b;
    }
    bool isBalanced(TreeNode* root) {
        return find(root);
    }
};