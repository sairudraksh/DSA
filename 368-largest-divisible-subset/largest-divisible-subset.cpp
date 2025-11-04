class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    vector<int> find(vector<int>&nums,int prev,int i){
        if(i>=n) return {};
        if(dp[i][prev+1].size()>0) return dp[i][prev+1];
        vector<int>notTake=find(nums,prev,i+1);

        vector<int>take;

        if(prev==-1 || nums[i]%nums[prev]==0){
            take=find(nums,i,i+1);
            take.insert(take.begin(),nums[i]);
        }

        if(take.size()>notTake.size()) return dp[i][prev+1]=take;
        else return dp[i][prev+1]=notTake;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        dp.assign(n, vector<vector<int>>(n + 1));  
        return find(nums,-1,0);
    }
};