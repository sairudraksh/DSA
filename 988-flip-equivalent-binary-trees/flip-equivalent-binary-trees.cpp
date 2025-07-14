class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        else if(root1==NULL || root2==NULL || root1->val!=root2->val) return false;
        bool notflipped=flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
        bool flipped=flipEquiv(root1->right,root2->left) && flipEquiv(root1->left , root2->right);

        if(notflipped==true || flipped==true) return true;
        else return false;
    }
};