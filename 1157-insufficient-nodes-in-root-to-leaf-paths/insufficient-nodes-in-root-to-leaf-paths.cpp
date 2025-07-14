class Solution {
public:
    TreeNode* find(TreeNode* root,int &limit,int sum){
        if(root==NULL) return NULL;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum>=limit) return root;
            else return NULL;
        }
        root->left=find(root->left,limit,sum);
        root->right=find(root->right,limit,sum);
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }
        return root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return find(root,limit,0);
    }
};