class Solution {
public:
    bool find(TreeNode* root,int curr,int &target){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL){
            curr+=root->val;
            if(curr==target) return true;
            return false;
        }
        return find(root->left,curr+root->val,target) ||  find(root->right,curr+root->val,target);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return find(root,0,targetSum);
    }
};