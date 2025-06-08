class Solution {
public:
    void summ(TreeNode* root,int &sum){
        if(root==NULL) return;
        sum=sum+root->val;
        summ(root->left,sum);
        summ(root->right,sum);
    }
    void answersum(TreeNode* root,int &finalans){
        if(root==NULL) return;
        finalans=finalans+root->val;
        answersum(root->left,finalans);
        answersum(root->right,finalans);
    }
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        int lftsum=0;
        int rghtsum=0;
        summ(root->left,lftsum);
        summ(root->right,rghtsum);
        int a=abs(lftsum-rghtsum);
        root->val=a;
        findTilt(root->left);
        findTilt(root->right);
        int finalans=0;
        answersum(root,finalans);
        return finalans;
    }
};