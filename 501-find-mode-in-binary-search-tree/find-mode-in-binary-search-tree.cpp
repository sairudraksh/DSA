class Solution {
public:
    void find(TreeNode* root,unordered_map<int,int>&map){
        if(root==NULL) return;
        map[root->val]++;
        find(root->left,map);
        find(root->right,map);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>v;
        if(root==NULL) return v;
        unordered_map<int,int>map;
        find(root,map);
        int max=INT_MIN;
        for(auto &x: map){
            if(x.second>max) max=x.second;
        }
        for(auto &x: map){
            if(x.second==max) v.push_back(x.first);
        }
        return v;
    }
};