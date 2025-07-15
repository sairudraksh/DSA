class Solution {
public:
    TreeNode* temp=NULL;
    void find(TreeNode* root,int val){
        if(root==NULL) return;
        if(root->val==val){
            temp=root;
            return;
        }
        if(val>root->val){
            find(root->right,val);
        }
        else find(root->left,val);
    }
    TreeNode* searchBST(TreeNode* root, int val){
        find(root,val);
        return temp;
    }
};