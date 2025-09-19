class Solution {
public:
    int totalsum=0;
    void find(TreeNode* root,int sum){
        if(root==NULL) return;
        sum=sum*10+root->val;

        if(root->left==NULL && root->right==NULL){
            totalsum+=sum;
        }

        find(root->left,sum);
        find(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        find(root,0);
        return totalsum;
    }
};