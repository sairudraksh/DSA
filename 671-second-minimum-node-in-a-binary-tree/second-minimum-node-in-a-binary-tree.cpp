class Solution {
public:
    long long maxval=LLONG_MAX;
    long long smaxval=LLONG_MAX;
    void find(TreeNode* root){
        if(root==NULL) return;
        if(root->val<maxval){
            smaxval=maxval;
            maxval=root->val;
        }
        else if(root->val>maxval && root->val <smaxval) smaxval=root->val;
        find(root->left);
        find(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        find(root);
        if(smaxval==LLONG_MAX) return -1;
        return (int)smaxval;
    }
};