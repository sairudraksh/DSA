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
    int findTime(TreeNode* target,unordered_map<TreeNode*,TreeNode*>&map){
        if(target==NULL) return 0;
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,int>visited;
        visited[target]=1;
        int maxi=0;

        while(q.size()>0){
            int res=q.size();
            int found=0;

            for(int i=0;i<res;i++){
                auto node=q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    found=1;
                    visited[node->left]=1;
                    q.push(node->left);
                }    

                if(node->right && !visited[node->right]){
                    found=1;
                    visited[node->right]=1;
                    q.push(node->right);
                }    
                if(map[node] && !visited[map[node]]){// for parent
                    found=1;
                    visited[map[node]]=1;
                    q.push(map[node]);
                }
            }
            if(found) maxi++;
        }
        return maxi;    
    }
    TreeNode* find(TreeNode* root,int start,unordered_map<TreeNode*,TreeNode*>&map){// do pass by reference as we want to change original value
        if(root==NULL) return NULL;

        TreeNode* res=NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            TreeNode* t=q.front();
            if(t->val==start) res=t;
            q.pop();
            if(t->left){
                map[t->left]=t;
                q.push(t->left);
            }
            if(t->right){
                map[t->right]=t;
                q.push(t->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>map;

        TreeNode* target=find(root,start,map);

        int time=findTime(target,map);
        return time;
    }
};