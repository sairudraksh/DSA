class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        int n=v.size();
        for(int i=0;i<n-1;i++){
            if(v[i]>=v[i+1]){
                return false;
            }
        }
        return true;
    }
};