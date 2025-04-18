class Solution {
public:
    void sumpath(TreeNode* root,int target,int sum,bool &flagg){
        if(root==NULL) return;
        sum=sum+root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==target) flagg=true;
            return;
        }
        sumpath(root->left,target,sum,flagg);
        sumpath(root->right,target,sum,flagg);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flagg=false;
        int sum=0;
        sumpath(root,targetSum,sum,flagg);
        return flagg;
    }
};