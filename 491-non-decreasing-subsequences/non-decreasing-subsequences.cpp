class Solution {
public:
    set<vector<int>>st;
    void find(int i,vector<int>&nums,vector<int>&ans){
        int n=nums.size();
        if(i==n){
            if(ans.size()>0 && ans.size()>=2) st.insert(ans);
            return;
        }

        if(ans.size()==0 || ans[ans.size()-1]<=nums[i]){
            ans.push_back(nums[i]);
            find(i+1,nums,ans);
            ans.pop_back();
        }
        find(i+1,nums,ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>ans;
        find(0,nums,ans);
        vector<vector<int>>finalans;
        for(auto &x:st){
            finalans.push_back(x);
        }
        return finalans;
    }
};