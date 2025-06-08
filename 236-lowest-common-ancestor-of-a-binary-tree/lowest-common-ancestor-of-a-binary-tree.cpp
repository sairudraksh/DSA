class Solution {
public:
    bool exists(TreeNode* root, TreeNode* p){
        if(root==NULL) return false;
        if(root->val==p->val) return true;
        if(exists(root->left,p) || exists(root->right,p)) return true;
        else return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) root;
        if(p==q) return p;
        else if(root==p) return p;
        else if(root==q) return q;
        else if(exists(root->left,q) && exists(root->right,p)) return root;
        else if(exists(root->left,p) && exists(root->right,q)) return root;
        else if(exists(root->left,p) && exists(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};