class Solution {
public:
    void find(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        find(root->left,v);
        v.push_back(root->val);
        find(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL) return 0;
        int min=INT_MAX;
        vector<int>v;
        find(root,v);
        for(int i=0;i<v.size()-1;i++){
            int ans=v[i+1]-v[i];
            if(ans<0) ans=ans*-1;
            if(ans<min){
                min=ans;
            }
        }
        return min;
    }
};