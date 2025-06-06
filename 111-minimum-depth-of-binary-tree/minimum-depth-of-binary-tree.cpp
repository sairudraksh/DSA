class Solution {
public:
    void find(TreeNode* root,int curr,int &min){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(curr<min) min=curr;
        }
        find(root->left,curr+1,min);
        find(root->right,curr+1,min);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int min=INT_MAX;
        int curr=1;
        find(root,curr,min);
        return min;
    }
};