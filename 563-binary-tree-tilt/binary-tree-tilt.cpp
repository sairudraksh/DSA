class Solution {
public:
    int summ(TreeNode* root,int &sum){//to find sum for absolute difference and return one side value
        if(root==NULL) return 0;
        sum=sum+root->val;
        summ(root->left,sum);
        summ(root->right,sum);
        return sum;
    }
    void sol(TreeNode* root){// to put new values in trees
        if(root==NULL) return;
        int suma=0;
        int sumb=0;
        root->val=abs(summ(root->left,suma)-summ(root->right,sumb));
        sol(root->left);
        sol(root->right);
    }
    int findsum(TreeNode* root,int &sum){//to find sum
        if(root==NULL) return 0;
        sum=sum+root->val;
        findsum(root->left,sum);
        findsum(root->right,sum);
        return sum;
    }
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        sol(root);
        int sum=0;
        return findsum(root,sum);
    }
};