class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int find(vector<int>&nums,int i,int rem){
        if(i>=n){
            if(rem==0) return 0;
            else return INT_MIN;
        }
        if(dp[i][rem]!=-1) return dp[i][rem];
        int newrem=(nums[i]+rem)%3;
        int a=find(nums,i+1,newrem);
        if(a!=INT_MIN) a+=nums[i];

        int b=find(nums,i+1,rem);

        if(a==INT_MIN && b==INT_MIN) return INT_MIN;
        if(a==INT_MIN) return b;
        if(b==INT_MIN) return a;
        return dp[i][rem]=max(a,b); 
    }
    int maxSumDivThree(vector<int>& nums){
        n=nums.size();
        dp.resize(n+1,vector<int>(3,-1));
        return find(nums,0,0);
    }
};