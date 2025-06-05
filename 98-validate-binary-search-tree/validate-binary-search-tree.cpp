class Solution {
public: 
    void find(TreeNode *root,vector<int>&v){
        if(root==NULL) return;
        find(root->left,v);
        v.push_back(root->val);
        find(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        find(root,v);
        int n=v.size();
        for(int i=1;i<n;i++){
            if(v[i]<=v[i-1]) return false;
        }
        return true;
    }
};