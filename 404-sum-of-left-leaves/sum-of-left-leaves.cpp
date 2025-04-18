class Solution {
public:
    void summ(TreeNode* root,int &sum){
        if(root==NULL) return;
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL) sum=sum+root->left->val;
        summ(root->left,sum);
        summ(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        int sum=0;
        summ(root,sum);
        return sum;
    }
};