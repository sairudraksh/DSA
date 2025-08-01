class Solution {
public:
    void find(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        v.push_back(root->val);
        find(root->left,v);
        find(root->right,v);

    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v;
        find(root1,v);
        find(root2,v);
        sort(v.begin(),v.end());
        return v;
    }
};