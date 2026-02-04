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
    int maxlen;
    void find(TreeNode* root,int len,int goRight){
        if(root==NULL) return;
        maxlen=max(maxlen,len);
        if(goRight==-1){
            if(root->right) find(root->right,1,0);
            if(root->left) find(root->left,1,1);
        }
        else if(goRight==1){
            if(root->right) find(root->right,len+1,0);
            if(root->left) find(root->left,1,1);
        }
        else{
            if(root->left) find(root->left,len+1,1);
            if(root->right) find(root->right,1,0);
        }
    }
    int longestZigZag(TreeNode* root) {
        maxlen=0;
        find(root,0,-1);
        return maxlen;
    }
};