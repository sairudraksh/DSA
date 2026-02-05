class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* temp=root->right;

        flatten(root->left);
        flatten(root->right);

        root->right=root->left;
        root->left=NULL;
        TreeNode* t=root;

        while(t!=NULL && t->right!=NULL){
            t=t->right;
        }
        t->right=temp;

    }
};