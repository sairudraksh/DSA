class Solution {
public:
    void subsets(vector<int>ans,int idx,int n,vector<int>nums,vector<vector<int>>&finalans){
        if(idx==n){
            finalans.push_back(ans);
            return;
        }
        subsets(ans,idx+1,n,nums,finalans);
        ans.push_back(nums[idx]);
        subsets(ans,idx+1,n,nums,finalans);
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        int idx=0;
        int n=nums.size();
        vector<vector<int>>finalans;
        subsets(ans,idx,n,nums,finalans);
        return finalans;
    }
};