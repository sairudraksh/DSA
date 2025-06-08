class Solution {
public:
    void find(TreeNode* root,long long &count,long long sum,int targetsum){
        if(root==NULL) return;
        sum=sum+root->val;
        if(sum==targetsum){
            count++;
        }
        find(root->left,count,sum,targetsum);
        find(root->right,count,sum,targetsum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        long long count=0;
        long long sum=0;
        find(root,count,sum,targetSum);
        count=count+pathSum(root->left,targetSum);
        count=count+pathSum(root->right,targetSum);
        return count;
    }
};