class Solution {
public:
    void find(TreeNode* root,int &sum){
        if(root==NULL) return;
        find(root->right,sum);
        root->val=root->val+sum;
        sum=root->val;
        find(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        find(root,sum);
        return root;
    }
};