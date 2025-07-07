class Solution {
public:
    TreeNode* find(TreeNode* root,int sum,int limit){
        if(root==NULL) return NULL;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum>=limit) return root;
            else return NULL;
        }
        root->left=find(root->left,sum,limit);
        root->right=find(root->right,sum,limit);

        if(root->left==NULL && root->right==NULL) return NULL;
        return root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return find(root,0,limit);
    }
};