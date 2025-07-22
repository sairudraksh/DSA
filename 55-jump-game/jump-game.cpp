class Solution {
public:
    vector<int>dp;
    int find(vector<int>&nums,int i){
        int n=nums.size();
        if(i>=n) return false;
        else if(i==n-1) return true;
        else if(nums[i]==0) return false;
        if(dp[i]!=-1) return dp[i];

        for(int k=1;k<=nums[i];k++){
            bool a=find(nums,i+k);
            if(a==true) return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        return find(nums,0);
    }
};