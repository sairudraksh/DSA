class Solution {
public:
    int maxdia=0;
    int find(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(find(root->left),find(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int lft=find(root->left);
        int rht=find(root->right);
        int dia=lft+rht;
        maxdia=max(dia,maxdia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxdia;
    }
};