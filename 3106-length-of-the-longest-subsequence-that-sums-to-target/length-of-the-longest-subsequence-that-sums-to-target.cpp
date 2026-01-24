class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>& nums,int &target,int i,int sum){
        if(sum>target) return INT_MIN;
        if(sum==target) return 0;
        if(i>=nums.size()) return INT_MIN;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take=find(nums,target,i+1,sum+nums[i]);
        int not_take=find(nums,target,i+1,sum);

        if(take==INT_MIN && not_take==INT_MIN) return dp[i][sum]=INT_MIN;
        return dp[i][sum]=max(1+take,not_take);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(1001,-1));
        int a=find(nums,target,0,0);
        if(a==INT_MIN) return -1;
        return a;
    }
};