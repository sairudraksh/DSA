class Solution {
public: 
    void traverse(TreeNode* root,int ans1,int ans2){
        if(root==NULL) return;
        if(root->val==ans1) root->val=ans2;
        else if(root->val==ans2) root->val=ans1;
        traverse(root->left,ans1,ans2);
        traverse(root->right,ans1,ans2);
    }
    void find(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        find(root->left,v);
        v.push_back(root->val);
        find(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        vector<int>v;
        find(root,v);
        int n=v.size();
        int ans1=0;
        int ans2=0;
        int count=0;
        for(int i=1;i<n;i++){
            if(v[i]<v[i-1]){
                if(count==0){
                    ans1=v[i-1];
                    ans2=v[i];
                    count++;
                }
                else if(count==1){
                    ans2=v[i];
                    count++;
                }
            }
            if(count==2) break;
        }
        traverse(root,ans1,ans2);
    }
};