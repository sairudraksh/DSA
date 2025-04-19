class Solution {
public:
    void validate(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        validate(root->left,v);
        v.push_back(root->val);
        validate(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        validate(root,v);
        int n=v.size();
        for(int i=0;i<n-1;i++){
            if(v[i]>=v[i+1]){
                return false;
            }
        }
        return true;
    }
};