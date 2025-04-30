class Solution {
public:
    void find(TreeNode* root,int curr,int target,int &sum){
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
    int maxLevelSum(TreeNode* root) {
        int maxsum=INT_MIN;
        int ans=1;
        int n=levels(root);
        for(int i=1;i<=n;i++){
            int sum=0;
            find(root,1,i,sum);
            if(sum>maxsum){
                maxsum=sum;
                ans=i;
            }
        }
        return ans;
    }
};