class Solution {
public:
    void sum(TreeNode* root,vector<int>v,int &summ){
        if(root==NULL) return;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            int n=v.size()-1;
            long long k=1;
            while(n>=0){
                int num=v[n]*k;
                summ=summ+num;
                n--;
                k=k*10;
            }
            return;
        }
        sum(root->left,v,summ);
        sum(root->right,v,summ);
    }
    int sumNumbers(TreeNode* root) {
        vector<int>v;
        int summ=0;
        sum(root,v,summ);
        return summ;
    }
};