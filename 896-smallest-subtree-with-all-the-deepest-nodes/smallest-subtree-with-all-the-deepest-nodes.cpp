class Solution {
public:
    bool exist(TreeNode* root,TreeNode* p){
        if(root==NULL) return false;
        if(root==p) return true;
        if(exist(root->left,p) || exist(root->right,p)) return true;
        return false;
    }
    TreeNode* exists(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        if((exist(root->left,p) && exist(root->right,q)) || (exist(root->left,q) && exist(root->right,p))) return root;
        if((exist(root->left,p) && !exist(root->right,q)) || (exist(root->left,q) && !exist(root->right,p))) return exists(root->left,p,q);
        if((!exist(root->left,p) && exist(root->right,q)) || (!exist(root->left,q) && exist(root->right,p))) return exists(root->right,p,q);
        return NULL;
    }
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    void find(TreeNode* root,int i,int &n,vector<TreeNode*>&v){
        if(root==NULL) return;
        find(root->left,i+1,n,v);
        if(i==n) v.push_back(root);
        find(root->right,i+1,n,v);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL) return NULL;
        int n=level(root);
        vector<TreeNode*>v;
        find(root,1,n,v);
        TreeNode* p=v[0];
        TreeNode* q=v[v.size()-1];
        TreeNode* a=exists(root,p,q);
        return a;
    }
};