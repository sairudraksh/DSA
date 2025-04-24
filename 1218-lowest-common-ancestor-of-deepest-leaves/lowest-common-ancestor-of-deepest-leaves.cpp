class Solution {
public:
    bool exists(TreeNode* root,TreeNode* target){
        if(root==NULL) return false; 
        if(root==target) return true;
        return exists(root->left,target) || exists(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        else if (exists(root->left,p) && exists(root->right,q)) return root;
        else if (!exists(root->left,p) && !exists(root->right,q)) return root;
        else if (exists(root->left,p) && !exists(root->right,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
    void findleaves(vector<TreeNode*>&v,TreeNode* root,int target,int curr){
        if(root==NULL) return;
        if(target==curr){
            v.push_back(root);
            return;
        }
        findleaves(v,root->left,target,curr+1);
        findleaves(v,root->right,target,curr+1);
    }
    int leaves(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(leaves(root->left),leaves(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) { 
        if(root==NULL) return NULL;
        int k=leaves(root);
        vector<TreeNode*>v;
        findleaves(v,root,k,1);
        int  n=v.size();
        TreeNode* p=v[0];
        TreeNode* q=v[n-1];
        return lowestCommonAncestor(root,p,q);
    }
};