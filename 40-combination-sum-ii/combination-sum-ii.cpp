class Solution {
public:
    vector<vector<int>>finalans;
    int n;
    void find(vector<int>&nums,int i,int target,vector<int>&ans){
        if(i>=n){
            if(target==0){
                finalans.push_back(ans); 
            }
            return;
        }

        if(nums[i]<=target){
            ans.push_back(nums[i]);
            find(nums,i+1,target-nums[i],ans);
            ans.pop_back();
        }


        int j=i+1;
        while(j<n && nums[j-1]==nums[j]){
            j++;
        }
        find(nums,j,target,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        find(nums,0,target,ans);
        return finalans;
    }
};