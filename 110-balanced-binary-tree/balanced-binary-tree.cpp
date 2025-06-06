class Solution {
public:
    int find(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(find(root->left),find(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int n1=find(root->left);
        int n2=find(root->right);
        if(n1>=n2){
            if((n1-n2)>1) return false;
        }
        else if(n2>n1){
            if((n2-n1)>1) return false;
        }
        bool a=isBalanced(root->left);
        bool b=isBalanced(root->right);
        if(a==true && b==true) return true;
        return false;
    }
};