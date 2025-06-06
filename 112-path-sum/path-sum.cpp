class Solution {
public:
    void find(TreeNode* root,int sum,int targetSum,bool &flagg){
        if(root==NULL) return;
        sum=sum+root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum) flagg=true;
            return;
        }
        find(root->left,sum,targetSum,flagg);
        find(root->right,sum,targetSum,flagg);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        int sum=0;
        bool flagg=false;
        find(root,sum,targetSum,flagg);
        return flagg;
    }
};