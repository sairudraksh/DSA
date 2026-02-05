class Solution {
public:
    int maxdia=0;
    int find(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(find(root->left),find(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        int len1=find(root->left);
        int len2=find(root->right);

        int dia=(len1+len2);
        maxdia=max(maxdia,dia);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxdia;
    }
};