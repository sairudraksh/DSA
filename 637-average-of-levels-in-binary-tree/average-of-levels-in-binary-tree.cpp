class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void find(TreeNode* root,int curr,int target,double &sum,double &count){
        if(root==NULL) return;
        if(curr==target){
            sum=sum+root->val;
            count++;
            return;
        }
        find(root->left,curr+1,target,sum,count);
        find(root->right,curr+1,target,sum,count);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int n=levels(root);
        int curr=1;
        vector<double>v1;
        if(root==NULL) return v1;
        for(int i=1;i<=n;i++){
            double sum=0;
            double count=0;
            find(root,curr,i,sum,count);
            v1.push_back(sum/count);
        }
        return v1;
    }
};