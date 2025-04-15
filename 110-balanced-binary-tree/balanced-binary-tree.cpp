class Solution {
public:
    int dept(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(dept(root->left),dept(root->right)); 
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int a=dept(root->left);
        int b=dept(root->right);
        bool c=isBalanced(root->left);
        bool d=isBalanced(root->right);
        if(!c || !d) return false;
        if(a>=b && a-b<=1) return true;
        else if(b>a && b-a<=1) return true;
        else return false;
    }
};