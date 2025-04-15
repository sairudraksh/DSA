class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        else if(p==NULL && q!=NULL || p!=NULL && q==NULL) return false;
        if(p->val!=q->val) return false;
        int lft=isSameTree(p->left,q->left);
        int rght=isSameTree(p->right,q->right);
        if(lft==false || rght ==false) return false;
        else return true;
    }
};