class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        bool leftoright=true;
        q.push(root);
        while(q.size()>0){
            int size=q.size();
            vector<int>v(size);
            for(int i=0;i<size;i++){
                auto p=q.front();
                q.pop();

                int idx;

                if(leftoright){
                    idx=i;
                }
                else{
                    idx=size-1-i;
                }

                v[idx]=p->val;

                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            if(leftoright){
                leftoright=false;
            }
            else{
                leftoright=true;
            }

            ans.push_back(v);
        }
        return ans;
    }
};