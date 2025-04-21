class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* temp=new TreeNode(val);
            return temp; 
        }
        if(root->val>val){
            if(root->left==NULL){
                TreeNode* temp=new TreeNode(val);
                root->left=temp;
                return root;
            }
            insertIntoBST(root->left,val);
        }
        else{
            if(root->right==NULL){
                TreeNode* temp=new TreeNode(val);
                root->right=temp;
                return root;
            }
            insertIntoBST(root->right,val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<n;i++){
            insertIntoBST(root,preorder[i]);
        }
        return root;
    }
};