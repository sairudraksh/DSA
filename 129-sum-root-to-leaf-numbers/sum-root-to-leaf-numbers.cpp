class Solution {
public:
    void find(TreeNode* root,int currsum,int &totalsum){
        if(root==NULL) return;
        currsum=currsum*10+root->val;
        if(root->left==NULL && root->right==NULL){
            totalsum=totalsum+currsum;
        }
        find(root->left,currsum,totalsum);
        find(root->right,currsum,totalsum);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        int currsum=0;
        int totalsum=0;
        find(root,currsum,totalsum);
        return totalsum;
    }
};