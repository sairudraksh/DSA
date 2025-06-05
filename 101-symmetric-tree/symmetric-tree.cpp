class Solution {
public:
    void rightside(TreeNode* root,vector<int>&v){
        if(root==NULL){
            v.push_back(INT_MIN);
            return;
        }
        v.push_back(root->val);
        rightside(root->right,v);
        rightside(root->left,v);
    }
    void leftside(TreeNode* root,vector<int>&v){
        if(root==NULL){
            v.push_back(INT_MIN);
            return;
        }
        v.push_back(root->val);
        leftside(root->left,v);
        leftside(root->right,v);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        vector<int>v1;
        vector<int>v2;
        leftside(root->left,v1);
        rightside(root->right,v2);
        int n1=v1.size();
        int n2=v2.size();
        if(n1!=n2) return false;
        for(int i=0;i<n1;i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};