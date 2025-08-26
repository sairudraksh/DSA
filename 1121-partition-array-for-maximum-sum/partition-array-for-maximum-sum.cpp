class Solution {
public:
    vector<int>dp;
    int find(int i,vector<int>&nums,int &k){
        if(i>=nums.size()) return 0;
        int ans=0;
        int maximum=0;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<nums.size() && j-i+1<=k;j++){
            maximum=max(maximum,nums[j]);

            ans=max(ans,((j-i+1)*maximum)+find(j+1,nums,k));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        dp.resize(n+1,-1);
        return find(0,arr,k);
    }
};