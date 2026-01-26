class Solution {
public:
    vector<string>v;
    void find(TreeNode* root,string &str){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            string org=str;
            str+=to_string(root->val);
            v.push_back(str);
            str=org;
            return;
        }
        string org=str;
        str+=to_string(root->val);
        str+="->";
        find(root->left,str);
        find(root->right,str);
        str=org;

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string str="";
        find(root,str);
        return v;
    }
};