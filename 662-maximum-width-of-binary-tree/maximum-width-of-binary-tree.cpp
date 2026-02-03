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
    int widthOfBinaryTree(TreeNode* root){
        queue<pair<TreeNode*,int>>q;

        q.push({root,0});
        long long maxans=0;
        while(q.size()>0){
            long long R=q.back().second;
            long long L=q.front().second;
            long long n=q.size();

            maxans=max(maxans,R-L+1);

            while(n--){
                
                TreeNode* temp=q.front().first;
                long long idx=q.front().second;

                if(temp->left){
                    q.push({temp->left,idx*2+1});
                }

                if(temp->right){
                    q.push({temp->right,idx*2+2});
                }
                q.pop();// by this popping is done from front
            }
        }
        return maxans;
    }
};