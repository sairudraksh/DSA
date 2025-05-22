class Solution {
public:
    void find(TreeNode* root,int &sum){
        if(root==NULL) return;
        if(root->val%2==0 && root->left!=NULL && root->left->left!=NULL){
            sum=sum+root->left->left->val;
        }
        if(root->val%2==0 && root->left!=NULL && root->left->right!=NULL){
            sum=sum+root->left->right->val;
        }

        if(root->val%2==0 && root->right!=NULL && root->right->left!=NULL){
            sum=sum+root->right->left->val;
        }
        if(root->val%2==0 && root->right!=NULL && root->right->right!=NULL){
            sum=sum+root->right->right->val;
        }
        find(root->left,sum);
        find(root->right,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        find(root,sum);
        return sum;
    }
};