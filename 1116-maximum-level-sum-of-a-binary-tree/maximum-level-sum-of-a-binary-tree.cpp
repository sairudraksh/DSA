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
    int find(TreeNode* root,int curr,int target){
        if(root==NULL) return 0;
        if(curr==target){
            return root->val;
        }
        return find(root->left,curr+1,target)+find(root->right,curr+1,target);
    }
    int levels( TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        int n=levels(root);
        int maximum=INT_MIN;
        int level=-1;
        for(int i=1;i<=n;i++){
            int a=find(root,1,i);
            if(a>maximum){
                maximum=a;
                level=i;
            }
        }
        return level;

    }
};