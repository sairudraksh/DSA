class Solution {
public:
    void getMinimumDifference(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        getMinimumDifference(root->left,v);
        v.push_back(root->val);
        getMinimumDifference(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>v;
        getMinimumDifference(root,v);
        int min=INT_MAX;
        int n=v.size();
        for(int i=1;i<n;i++){
            int diff=abs(v[i]-v[i-1]);
            if(diff<min) min=diff;
        }
        return min;
    }
};