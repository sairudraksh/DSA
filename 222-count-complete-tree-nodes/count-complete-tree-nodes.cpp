class Solution {
public:
    int count(TreeNode* root){
        if(root==NULL) return 0;
        return 1+count(root->left)+count(root->right);

    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return count(root);
    }
};