class Solution {
public:
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return NULL;
        return depth(root);
    }
};