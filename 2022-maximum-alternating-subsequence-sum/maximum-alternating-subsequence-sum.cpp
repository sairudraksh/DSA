class Solution {
public:
    int n;
    vector<vector<long long>>dp;
    long long find(vector<int>&nums,int i,bool add){
        if(i>=n) return 0;
        if(dp[i][add]!=-1) return dp[i][add];
        if(add){
            return dp[i][add]=1LL*max(nums[i]+find(nums,i+1,false),find(nums,i+1,add));
        }
        else{
            return dp[i][add]=1LL*max(find(nums,i+1,true)-nums[i],find(nums,i+1,false));
        }
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,vector<long long>(2,-1));
        return find(nums,0,true);
    }
};