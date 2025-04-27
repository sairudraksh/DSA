class Solution {
public:
    void sminimum(TreeNode* root,long long &min,long long &smin){
        if(root==NULL) return;
        if(root->val<smin && root->val>min){
            smin=root->val;
        }
        sminimum(root->left,min,smin);
        sminimum(root->right,min,smin);
    }
    void minimum(TreeNode* root,long long &min){
        if(root==NULL) return;
        if(root->val<min){
            min=root->val;
        }
        minimum(root->left,min);
        minimum(root->right,min);
    }
    int findSecondMinimumValue(TreeNode* root) {
        long long min=LLONG_MAX;
        long long smin=LLONG_MAX;
        minimum(root,min);
        sminimum(root,min,smin);
        if(smin==LLONG_MAX) return -1;
        return smin;
    }
};
