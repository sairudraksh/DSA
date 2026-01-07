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
    long long maximum=0;

    int findSum(TreeNode* root){
        if(root==NULL) return 0;
        return root->val+findSum(root->left)+findSum(root->right);
    }
    int find(TreeNode* root,int curr,int &total){
        if(root==NULL) return 0;
        int leftSum=find(root->left,curr,total);
        int rightSum=find(root->right,curr,total);

        long long part1=root->val+rightSum+leftSum;
        long long part2=total-part1;

        maximum=max(maximum,part1*part2);

        return part1;

    }
    int maxProduct(TreeNode* root) {
        int total=findSum(root);
        int a=find(root,0,total);
        return maximum%(1000000007);
    }
};