class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(k,vector<int>(n,1));// at max modulo can be k because after that it will completely divide it
        int maxval=-1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int mod=(nums[i]+nums[j])%k;

                dp[mod][i]=max(dp[mod][i],1+dp[mod][j]);
                maxval=max(maxval,dp[mod][i]);
            }
        }
        return maxval;
    }
};