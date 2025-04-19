class Solution {
public:
    TreeNode* prev=NULL;
    bool flag=true;
    void validate(TreeNode* root){
        if(root==NULL) return;
        validate(root->left);
        if(prev!=NULL){
            if(root->val<=prev->val){
                flag=false;
                return;
            }
        }
        prev=root;
        validate(root->right);
    }
    bool isValidBST(TreeNode* root) {
        validate(root);
        return flag;
    }
};