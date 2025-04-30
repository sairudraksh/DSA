class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;
        root1->val=root1->val+root2->val;
        root1->left=mergeTrees(root1->left,root2->left);
        root1->right=mergeTrees(root1->right,root2->right);
        return root1;
    }
};//many nodes can point on a single node but a node can point ont 2 nodes only;