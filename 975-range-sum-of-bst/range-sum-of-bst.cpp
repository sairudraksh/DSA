class Solution {
public:
    void find(TreeNode* root,int a,int b,int &sum){
        if(root==NULL) return;
        if(root->val>=a && root->val<=b) sum=sum+root->val;
        if(a<root->val && b<root->val) find(root->left,a,b,sum);
        else if(a>root->val && b>root->val) find(root->right,a,b,sum);
        else{
            find(root->left,a,b,sum);
            find(root->right,a,b,sum);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        find(root,low,high,sum);
        return sum;
    }
};