class Solution {
public:
    void find(TreeNode* root,vector<vector<string>>&v,int row,int col,int height){
        if(root==NULL) return;
        v[row][col] = to_string(root->val);
        if(root->left!=NULL){
            int x=row+1;
            int y=col-pow(2,height-row-2);
            v[x][y]=to_string(root->left->val);
            find(root->left,v,x,y,height);
        }
        if(root->right!=NULL){
            int a=row+1;
            int b=col+pow(2,height-row-2);
            v[a][b]=to_string(root->right->val);
            find(root->right,v,a,b,height);
        }
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right)); 
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height=levels(root);
        int rows=height;
        int cols=pow(2, height)-1;
        vector<vector<string>>v(rows,vector<string>(cols, ""));
        find(root,v,0,(cols-1)/2,height);
        return v;   
    }
};