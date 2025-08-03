class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>&nums,int target,int idx,vector<int>&v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0) return;
        if(idx>=nums.size()) return;
        for(int i=idx;i<nums.size();i++){
            v.push_back(nums[i]);
            find(nums,target-nums[i],i,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>v;
        find(nums,target,0,v);
        return ans;
    }
};