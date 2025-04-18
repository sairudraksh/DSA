class Solution {
public:
    int path(TreeNode* root,long long currsum,int target,int &couunt){
        if(root==NULL) return 0;
        currsum=currsum+root->val;
        if(currsum==target) couunt++;
        path(root->left,currsum,target,couunt);
        path(root->right,currsum,target,couunt);
        return couunt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        long long currsum=0;
        int couunt=0;
        int count=path(root,currsum,targetSum,couunt);
        count=count+(pathSum(root->left,targetSum)+pathSum(root->right,targetSum));
        return count;
    }
};