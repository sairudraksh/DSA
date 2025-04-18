class Solution {
public:
    void mindept(TreeNode* root,int currdept,int &minidept){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(currdept<minidept) minidept=currdept;
        }
        mindept(root->left,currdept+1,minidept);
        mindept(root->right,currdept+1,minidept);            
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int currdept=1;
        int minidept=INT_MAX;
        mindept(root,currdept,minidept);
        return minidept;
    }
};