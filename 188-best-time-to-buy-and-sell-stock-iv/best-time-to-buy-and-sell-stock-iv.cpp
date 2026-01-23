class Solution {
public:
    int n;
    int dp[2][1005][105];
    int find(vector<int>& nums,bool take,int i,int k){
        if(i>=nums.size()) return 0;
        if(k==0) return 0;
        if(dp[take][i][k]!=-1) return dp[take][i][k];
        if(take==false){
            return dp[take][i][k]=max(find(nums,false,i+1,k),find(nums,true,i+1,k)-nums[i]);
        }
        else{
            return dp[take][i][k]=max(find(nums,true,i+1,k),find(nums,false,i+1,k-1)+nums[i]);
        }
    }
    int maxProfit(int k, vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof dp);
        return find(nums,0,false,k);
    }
};