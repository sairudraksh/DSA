class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&nums,int n,int i,int j){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(nums[i]-find(nums,n,i+1,j),nums[j]-find(nums,n,i,j-1));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        dp.resize(n+1,vector<int>(n+1,-1));
        int a=find(nums,n,0,n-1);
        if(a<0) return false;
        else return true;
    }
};