class Solution {
public:
    void find(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        v.push_back(root->val);
        find(root->left,v);
        find(root->right,v);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>v;
        find(root,v);
        sort(v.begin(),v.end());
        int n=v.size();
        TreeNode* newroot=new TreeNode(v[0]);
        root=newroot;
        for(int i=1;i<n;i++){
            TreeNode* newroot1=new TreeNode(v[i]);
            newroot->right=newroot1;
            newroot=newroot1;
        }
        return root;
    }
};