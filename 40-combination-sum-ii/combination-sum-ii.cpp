class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>&nums,int target,int i,vector<int>&v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(i==nums.size()) return;
        if(nums[i]<=target){
            v.push_back(nums[i]);
            find(nums,target-nums[i],i+1,v);
            v.pop_back();
            
        }
        int j=i+1;
        while(j<nums.size() && nums[j]==nums[j-1]) j++;
        find(nums,target,j,v);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        ans.clear();
        int i=0;
        find(nums,target,i,v);
        return ans;
    }
};