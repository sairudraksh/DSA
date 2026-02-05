/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,vector<pair<int,int>>>mp;
    void find(TreeNode* root,int row,int col){
        if(root==NULL) return;;

        mp[col].push_back({row,root->val});

        find(root->left,row+1,col-1);
        find(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        find(root,0,0);
        vector<vector<int>>result;
        for(auto x:mp){
            vector<pair<int,int>>v=x.second;
            vector<int>ans;
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                auto t=v[i];
                ans.push_back(t.second);
            }
            result.push_back(ans);
        }
        return result;
    }
};