class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    vector<int> find(vector<int>&nums,int i,int prev){
        if(i>=nums.size()) return {};
        if(dp[i][prev+1].size()>0) return dp[i][prev+1];
        vector<int>notTake=find(nums,i+1,prev);

        vector<int>take;

        if(prev==-1 || nums[i]%nums[prev]==0){
            take=find(nums,i+1,i);
            take.insert(take.begin(),nums[i]);
        }
        if(take.size()>notTake.size()) return dp[i][prev+1]=take;
        return dp[i][prev+1]=notTake; 
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
         dp.assign(n, vector<vector<int>>(n + 1)); 
        return find(nums,0,-1);    
    }
};