class Solution {
public:
    void find(TreeNode* root,int &ans1,int &ans2,int &x,int &y){
        if(x!=0 && y!=0) return;
        else if(root==NULL) return;
        else if(root->val==ans1){
            if(x==0){
                root->val=ans2;
                x++;
            }
        }
        else if(root->val==ans2){
            if(y==0){
                root->val=ans1;
                y++;
            }
        }
        find(root->left,ans1,ans2,x,y);
        find(root->right,ans1,ans2,x,y);
    }
    void Inorder(TreeNode* root, vector<int>&v){
        if(root==NULL) return;
        Inorder(root->left,v);
        v.push_back(root->val);
        Inorder(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        vector<int>v;
        Inorder(root,v);
        int ans1=0;
        int ans2=0;
        int count=0;
        for(int i=0;i<v.size()-1;i++){
            if(count==0){
                if(v[i]>v[i+1]){
                    ans1=v[i];
                    ans2=v[i+1];
                    count++;
                }
            }
            else if(v[i]>v[i+1]){
                ans2=v[i+1];
            }
        }
        int x=0;
        int y=0;
        find(root,ans1,ans2,x,y);
    }
};