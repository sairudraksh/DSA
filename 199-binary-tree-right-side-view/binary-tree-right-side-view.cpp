class Solution {
public:
    void find(TreeNode* root,int target,int curr,queue<int> &q){
        if(root==NULL) return;
        if(curr==target){
            if(q.size()>=1) q.pop();
            q.push(root->val);
        }
        find(root->left,target,curr+1,q);
        find(root->right,target,curr+1,q);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    vector<int> rightSideView(TreeNode* root) {
        int n=levels(root);
        vector<int>v1;
        if(root==NULL) return v1;
        v1.push_back(root->val);
        queue<int>q;
        for(int i=2;i<=n;i++){
            find(root,i,1,q);
            v1.push_back(q.front());
            q.pop();
        }
        return v1;
    }
};