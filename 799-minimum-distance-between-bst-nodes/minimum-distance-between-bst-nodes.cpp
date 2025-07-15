class Solution {
public:
    void find(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        find(root->left,v);
        v.push_back(root->val);
        find(root->right,v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        find(root,v);
        int max=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            int ans=abs(v[i+1]-v[i]);
            if(ans<max) max=ans;
        }
        return max;
    } 
};