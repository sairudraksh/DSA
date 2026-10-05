class Solution {
public:
    long long dp[100001][3][3];
    long long find(vector<int>&nums,int parity,int del,int i){
        if(i>=nums.size()) return 0;

        long long ans=0;

        long long val=0;
        if(dp[i][parity][del]!=-1) return dp[i][parity][del];
        if(parity==1){
            val=-1LL*nums[i];
        }
        else val=nums[i];

        int newParity=1-parity;

        long long take=val+find(nums,newParity,del,i+1);
        ans=max(ans,take);

        if(del==1){
            long long skip=find(nums,parity,0,i+1);
            ans=max(ans,skip);
        }

        return dp[i][parity][del]=ans;

    }
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=INT_MIN;
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            ans=max(ans,nums[i]+find(nums,1,1,i+1));
        }
        return ans;
    }
};