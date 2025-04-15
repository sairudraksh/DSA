class Solution {
public:
    int maxdia=0;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(helper(root->left),helper(root->right));

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int lft=helper(root->left);
        int rht=helper(root->right);
        int dia=lft+rht;
        maxdia=max(maxdia,dia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxdia;
        
    }
};