class Solution {
public:
    void treepath(vector<string>&s,string st,TreeNode* root){
        if(root==NULL) return;
        st+=to_string(root->val);//just add to string
        if(root->left!=NULL || root->right!=NULL) st+="->";// add this everytime expect at leaf(last) node
        if(root->left==NULL && root->right==NULL){//push ant ans when we are as last or leaf node
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