class Solution {
public:
    void find(TreeNode* root,int &sum){
        if(root==NULL) return;
        find(root->right,sum);
        sum+=root->val;
        root->val=sum;
        find(root->left,sum);

    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        find(root,sum);
        return root;
    }
};