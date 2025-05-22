class Solution {
public:
    unordered_map<int,int>map;
    void find(TreeNode* root){
        if(root==NULL) return;
        map[root->val]++;
        find(root->left);
        find(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>v;
        if(root==NULL) return v;
        find(root);
        int max=INT_MIN;
        for(auto x: map){
            if(x.second>max) max=x.second;
        }
        for(auto x: map){
            if(x.second==max) v.push_back(x.first);
        }
        return v;
    }
};