class Solution {
public:
    void find(TreeNode* root,int &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) return;
        if(root->val%2==0){
            if(root->left!=NULL){
                if(root->left->left!=NULL){
                    ans+=root->left->left->val;
                }
                if(root->left->right!=NULL){
                    ans+=root->left->right->val;
                }
            }

            if(root->right!=NULL){
                if(root->right->left!=NULL){
                    ans+=root->right->left->val;
                }
                if(root->right->right!=NULL){
                    ans+=root->right->right->val;
                }
            }
        }
        find(root->left,ans);
        find(root->right,ans);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        find(root,sum);
        return sum;
    }
};