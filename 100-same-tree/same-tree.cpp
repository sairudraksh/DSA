class Solution {
public:
    bool find(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val!=q->val) return false;
        return find(p->left,q->left) && find(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return find(p,q);
    }
};