class Solution {
public:
    int n;
    int dp[100001];
    bool find(vector<int>&nums,int i){
        if(i>=n) return true;

        bool ans=false;
        if(dp[i]!=-1) return dp[i];
        if(i+1<n){
            if(nums[i]==nums[i+1]){
                ans=ans || find(nums,i+2);
            }
        }
        if(i+2<n){
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                ans=ans || find(nums,i+3);
            }
            if(nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1){
                ans=ans||find(nums,i+3);
            }
        }

        return dp[i]=ans;
    }
    bool validPartition(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return find(nums,0);
    }
};