class Solution {
public:
    long long maxTree(TreeNode* root){
        if(root==NULL) return LLONG_MIN;
        return max((long long)(root->val),max(maxTree(root->left),maxTree(root->right)));
    }
    long long minTree(TreeNode* root){
        if(root==NULL) return LLONG_MAX;
        return min((long long)(root->val),min(minTree(root->left),minTree(root->right)));
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        else if((long long)(root->left)==NULL && root->right==NULL) return true;
        else if((long long)(root->val) <= maxTree(root->left)) return false;
        else if((long long)(root->val) >= minTree(root->right)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};