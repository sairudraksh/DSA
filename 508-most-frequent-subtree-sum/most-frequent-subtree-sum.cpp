class Solution {
public:
    unordered_map<int,int>map;
    void find(TreeNode* root,int &sum){
        if(root==NULL) return ;
        find(root->left,sum);
        sum=sum+root->val;
        find(root->right,sum);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>v;
        if(root==NULL) return v;
        int sum=0;
        find(root,sum);
        map[sum]++;
        findFrequentTreeSum(root->left);
        findFrequentTreeSum(root->right);
        int max=INT_MIN;
        for(auto ele:map){
            if(ele.second>max) max=ele.second;
        }
        for(auto ele :map){
            if(ele.second==max) v.push_back(ele.first);
        }
        return v;
    }
};