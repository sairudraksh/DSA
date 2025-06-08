class Solution {
public:
    void find(TreeNode* root,int &count,int k,int &ans){
        if(count==k) return;
        if(root==NULL) return;
        find(root->left,count,k,ans);
        if(count==k) return;
        ans=root->val;
        count++;
        find(root->right,count,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return 0;
        vector<int>v;
        int count=0;
        int ans=0;
        find(root,count,k,ans);
        return ans;
    }
};