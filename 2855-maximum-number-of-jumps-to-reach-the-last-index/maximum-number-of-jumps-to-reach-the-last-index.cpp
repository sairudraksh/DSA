class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(n,0);
        unordered_map<int,int>map;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(abs(nums[j]-nums[i])<=target){
                    if(dp[j]!=0 || j==0){
                        if(dp[i]<=dp[j]){
                            dp[i]=dp[j]+1;
                        }
                    }
                }
            }
        }
        if(dp[n-1]==0) return -1;
        return dp[n-1];
    }
};