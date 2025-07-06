class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&nums,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(nums[i]-find(nums,i+1,j),nums[j]-find(nums,i,j-1));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        dp.resize(n+1,vector<int>(n+1,-1));
        // if returned value is greater than 1 means alice have greater value
        int a=find(nums,0,n-1);
        if(a>=0) return true;
        else return false;
    }
};