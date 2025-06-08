class Solution {
public:
    unordered_map<int,int>map;
    void find(TreeNode* root,int &sum){
        if(root==NULL) return;
        sum=sum+root->val;
        find(root->left,sum);
        find(root->right,sum);
    }
    vector<int> findFrequentTreeSum(TreeNode* root){
        vector<int>v;
        if(root==NULL) return v;
        int sum=0;
        find(root,sum);
        map[sum]++;
        findFrequentTreeSum(root->left);
        findFrequentTreeSum(root->right);
        int max=INT_MIN;
        for(auto &x:map){
            if(x.second>max) max=x.second;
        }
        for(auto &x:map){
            if(x.second==max) v.push_back(x.first);
        }
        return v;
    }
};