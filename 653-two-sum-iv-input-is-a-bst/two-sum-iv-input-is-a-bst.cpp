class Solution {
public:
    void find(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        v.push_back(root->val);
        find(root->left,v);
        find(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        find(root,v);
        int n=v.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(v[i]+v[j]==k){
                    return true;
                }
            }
        }
        return false;
    }
};