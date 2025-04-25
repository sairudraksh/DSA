class Solution {
public: 
    void leftside(TreeNode* root,vector<int>&v1){
        if(root==NULL){
            v1.push_back(-100);
            return;
        }
        v1.push_back(root->val);
        leftside(root->left,v1);
        leftside(root->right,v1);
    }
    void rightside(TreeNode* root,vector<int>&v1){
        if(root==NULL){
            v1.push_back(-100);
            return;
        }
        v1.push_back(root->val);
        rightside(root->right,v1);
        rightside(root->left,v1);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        vector<int>v1;
        leftside(root->left,v1);
        vector<int>v2;
        rightside(root->right,v2);
        if(v1.size()!=v2.size()){
            return false;
        }
        int n=v1.size();
        for(int i=0;i<n;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
};