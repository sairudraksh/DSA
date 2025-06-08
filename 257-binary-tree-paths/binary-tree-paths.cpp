class Solution {
public:
    void find(TreeNode* root,string str,vector<string>&v){
        if(root==NULL) return;
        str+=to_string(root->val);
        if(root->left!=NULL || root->right!=NULL) str+="->";
        if(root->left==NULL && root->right==NULL){
            v.push_back(str);
        }
        find(root->left,str,v);
        find(root->right,str,v);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        string str="";
        if(root->left==NULL && root->right==NULL){
            str+=to_string(root->val);
            v.push_back(str);
            return v;
        }
        find(root,str,v);
        return v;
    }
};