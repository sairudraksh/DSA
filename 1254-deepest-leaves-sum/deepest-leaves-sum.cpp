class Solution {
public:
    int prevcurr=-1;
    int sum=0;
    void find(TreeNode* root,int curr){
        if(root==NULL) return;
        if(curr==prevcurr){
            sum+=root->val;
        }
        if(curr>prevcurr){
            prevcurr=curr;
            sum=0;
            sum+=root->val;
        }
        find(root->left,curr+1);
        find(root->right,curr+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        find(root,1);
        return sum;
    }
};