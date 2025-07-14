class Solution {
public:
    bool find(TreeNode* root,vector<int>&v,int curr,int &target){
        if(root==NULL && curr!=target) return false;
        else if(root==NULL && curr==target){
            v.push_back(NULL);
            return true;
        }
        else if(curr==target){
            v.push_back(root->val);
            return true;
        }
        bool a=find(root->left,v,curr+1,target);
        bool b=find(root->right,v,curr+1,target);
        if(a==false || b==false) return false;
        else return true;

    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    bool isCompleteTree(TreeNode* root) {
        int n=levels(root);
        vector<int>v;
        bool a=find(root,v,1,n);
        if(a==false) return false;
        else{
            for(int i=0;i<v.size()-1;i++){
                if(v[i]==NULL && v[i+1]!=NULL) return false;
            }
        }
        return true;
    }
};