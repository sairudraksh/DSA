class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        int pickup=root->val;
        if (dp.count(root)) return dp[root];
        if(root->left!=NULL){
            pickup+=rob(root->left->left);
            pickup+=rob(root->left->right);
        }
        if(root->right!=NULL){
            pickup+=rob(root->right->left);
            pickup+=rob(root->right->right);
        }
        int notpickup=rob(root->left)+rob(root->right);
        return dp[root]=max(pickup,notpickup);
    }
};