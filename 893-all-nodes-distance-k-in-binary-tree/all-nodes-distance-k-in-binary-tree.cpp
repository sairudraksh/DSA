/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>v;
    void find(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&map,int k){
        if(root==NULL) return;

        queue<TreeNode*>q;
        q.push(root);   
        unordered_map<TreeNode*,int>visited;
        visited[root]=1;
        while(q.size()>0 && k>0){

            int res=q.size();

            for(int i=0;i<res;i++){
                auto x=q.front();
                q.pop();
                if(x->left && !visited[x->left]){
                    visited[x->left]=1;
                    q.push(x->left);
                }

                if(x->right && !visited[x->right]){
                    visited[x->right]=1;
                    q.push(x->right);
                }
                
                if(map[x] && !visited[map[x]]){
                    visited[map[x]]=1;
                    q.push(map[x]);
                }
            }
            k--;
        }
        while(q.size()>0){
            auto x=q.front();
            q.pop();
            v.push_back(x->val);
        }
    }
    TreeNode* findtarget(TreeNode* root,TreeNode* target,unordered_map<TreeNode*,TreeNode*>&map){
        if(root==NULL) return NULL;

        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(q.size()>0){
            TreeNode* t=q.front();
            q.pop();

            if(t==target) res=t;

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        unordered_map<TreeNode*,TreeNode*>map;
        TreeNode* temp=findtarget(root,target,map);

        find(temp,map,k);

        return v;
    }
};