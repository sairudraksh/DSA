class Solution {
public:
    int maxx=INT_MIN;
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+ max(level(root->left),level(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int lft=level(root->left);
        int riht=level(root->right);
        int dai=lft+riht;
        maxx= max(maxx,dai);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxx;
    }
};