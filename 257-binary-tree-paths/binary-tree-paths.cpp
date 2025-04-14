class Solution {
public:
    void treepath(vector<string>&s,string st,TreeNode* root){
        if(root==NULL) return;
        st+=to_string(root->val);
        if(root->left!=NULL || root->right!=NULL) st+="->";
        if(root->left==NULL && root->right==NULL){
            s.push_back(st);
            return;
        }
        treepath(s,st,root->left);
        treepath(s,st,root->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        treepath(v,"",root);
        return v;
    }
};