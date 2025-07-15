class Solution {
public:
    void leftside(TreeNode* root,vector<int>&v){
        if(root==NULL){
            v.push_back(-100);
            return;
        }
        v.push_back(root->val);
        leftside(root->left,v);
        leftside(root->right,v);
    }

    void rightside(TreeNode* root,vector<int>&v){
        if(root==NULL){
            v.push_back(-100);
            return;
        }
        v.push_back(root->val);
        rightside(root->right,v);
        rightside(root->left,v);
    }

    bool isSymmetric(TreeNode* root) {
        vector<int>v1;
        leftside(root->left,v1);
        vector<int>v2;
        rightside(root->right,v2);
        if(v1.size()!=v2.size()) return false;
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};