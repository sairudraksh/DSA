class Solution {
public:
    bool find(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL) return true;
        if((p==NULL && q!=NULL) ||  (p!=NULL && q==NULL)){
            return false;
        }
        if(p->val!=q->val) return false;
        bool a=true;
        bool b=true;
        a=find(p->left,q->left);
        b=find(p->right,q->right);
        if(a==true && b==true) return true;
        else return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool a=find(p,q);
        return a;
    }
};