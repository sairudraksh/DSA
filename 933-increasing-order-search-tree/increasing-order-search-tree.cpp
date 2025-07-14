class Solution {
public:
    void find(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        find(root->left,v);
        v.push_back(root->val);
        find(root->right,v);
    }
    TreeNode* increasingBST(TreeNode* roott) {
        vector<int>v;
        find(roott,v);
        TreeNode* root=new TreeNode(v[0]);
        TreeNode* rootans=root;
        for(int i=1;i<v.size();i++){
            TreeNode* root1=new TreeNode(v[i]);
            root->right=root1;
            root=root1;
        }
        return rootans;
    }
};