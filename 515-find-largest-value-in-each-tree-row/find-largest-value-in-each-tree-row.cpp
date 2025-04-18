class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void largest(TreeNode* root,int curr,int target,int &max){
        if(root==NULL) return;
        if(curr==target && root->val>max){
            max=root->val;
            return;
        }
        largest(root->left,curr+1,target,max);
        largest(root->right,curr+1,target,max);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>v;
        if(root==NULL){
            return v;
        }
        int n=levels(root); 
        for(int i=1;i<=n;i++){
            int max=INT_MIN; 
            largest(root,1,i,max);
            v.push_back(max);
        }
        return v;
    }
};