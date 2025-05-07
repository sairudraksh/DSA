class Solution {
public:
    void find(TreeNode* root,int curr,int target,int& sum){
        if(root==NULL) return;
        if(curr==target){
            sum=sum+root->val;
            return;
        }
        find(root->left,curr+1,target,sum);
        find(root->right,curr+1,target,sum);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL) return 0;
        int n=levels(root);
        if(n==1) return root->val;
        int sum=0;
        int target=n;
        int curr=1;
        find(root,curr,target,sum);
        return sum;
    }
};