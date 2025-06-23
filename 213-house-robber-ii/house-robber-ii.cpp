class Solution {
public:
    vector<vector<int>>dp;
    int find(int i,vector<int>&nums,bool flagg ,int &count,int &n){
        if(i>=n) return 0;
        if(i==n-1 && flagg==true) return nums[i];
        if(i==n-1 && flagg==false) return 0;
        if(dp[i][flagg]!=-1) return dp[i][flagg];
        if(count==0){
            count++;
            return dp[i][flagg]=max(nums[i]+find(i+2,nums,false,count,n),find(i+1,nums,true,count,n));
        }
        return dp[i][flagg]=max(nums[i]+find(i+2,nums,flagg,count,n),find(i+1,nums,flagg,count,n));
    }
    int rob(vector<int>& nums) {
        dp.resize(1001,vector<int>(1001,-1));
        bool flagg=true;
        int count=0;
        int i=0;
        int n=nums.size();
        return find(i,nums,flagg,count,n);
    }
};