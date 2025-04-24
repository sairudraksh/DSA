class Solution {
public:
    void greatestsum(TreeNode* root,int &sum){
        if(root==NULL) return;
        greatestsum(root->right,sum);
        root->val=root->val+sum;
        sum=root->val;
        greatestsum(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        greatestsum(root,sum);
        return root;
    }
};