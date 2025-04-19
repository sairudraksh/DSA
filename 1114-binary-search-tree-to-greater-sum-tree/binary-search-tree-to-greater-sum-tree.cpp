class Solution {
public:
    int sum=0;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->right);
        if(root==NULL) return;
        root->val=root->val+sum;
        sum=root->val;
        inorder(root->left);

    }
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        return root;  
    }
};