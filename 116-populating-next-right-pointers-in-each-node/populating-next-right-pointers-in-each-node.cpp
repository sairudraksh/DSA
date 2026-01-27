/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int levels(Node* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void find(Node* root,int &i,int &count,int curr,int &target,Node* &prev){
        if(root==NULL) return;
        if(curr==target){
            i++;
            if(prev!=NULL){
                prev->next=root;
            }
            prev=root;
            if(i==count){
                root->next=NULL;
                return;
            }
            return;
        }
        find(root->left,i,count,curr+1,target,prev);
        find(root->right,i,count,curr+1,target,prev);
    }
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        int n=levels(root);
        int count=1;
        for(int i=1;i<=n;i++){
            Node* prev=NULL;
            int j=1;
            find(root,j,count,1,i,prev);
            count=count*2;
        }
        return root;
    }
};