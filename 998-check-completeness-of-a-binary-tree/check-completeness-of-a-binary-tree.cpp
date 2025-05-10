class Solution {
public:
    void find(TreeNode* root,int curr,int target,vector<int>&v){
        if(root==NULL){
            v.push_back(INT_MIN);
            return;
        }
        if(curr==target){
            v.push_back(root->val);
            return;
        }
        find(root->left,curr+1,target,v);
        find(root->right,curr+1,target,v);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return false;
        int n=levels(root);
        for(int i=1;i<=n;i++){
            vector<int>v;
            int curr=1;
            int target=i;
            find(root,curr,target,v);
            if(target<n){
                for(int i=0;i<v.size();i++){
                    if(v[i]==INT_MIN) return false;
                }
            }
            if(target==n){
                for(int i=0;i<v.size();i++){
                    if(v[i]==INT_MIN){
                        for(int k=i;k<v.size();k++){
                            if(v[k]!=INT_MIN) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};