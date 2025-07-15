class Solution {
public:
    long long maximum;
    long long smax;
    void find(TreeNode* root){
        if(root==NULL) return;
        if(root->val<maximum){ 
            smax=maximum;
            maximum=root->val;
        }
        else if(root->val<smax && root->val>maximum && root->val!=maximum){
            smax=root->val;
        } 
        find(root->left);
        find(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        maximum=LLONG_MAX;
        smax=LLONG_MAX;
        find(root);
        if(smax==LLONG_MAX) return -1;
        return (int)smax;
    }
};