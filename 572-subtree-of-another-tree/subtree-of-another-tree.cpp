class Solution {
public:
    bool flagg=false;
    bool compare(TreeNode* root,TreeNode* subRoot){
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;
        bool a=true;
        bool b=true;
        if(root->val!=subRoot->val) return false;
        if(root->left==NULL && subRoot->left!=NULL || root->left!=NULL && subRoot->left==NULL) return false;
        if(root->right==NULL && subRoot->right!=NULL || root->right!=NULL && subRoot->right==NULL) return false;
        a=compare(root->left,subRoot->left);
        b=compare(root->right,subRoot->right);
        if(a==true && b==true) return true;
        else return false;
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(flagg==true) return true;
        if(root==NULL) return false;
        if(root->val==subRoot->val){
            bool a=compare(root,subRoot);
            if(a==true) flagg=true;
        }
        isSubtree(root->left,subRoot);
        isSubtree(root->right,subRoot);
        return flagg;
    }
};