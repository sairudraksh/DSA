class Solution {
public:
    int dp[100005][2][2];
    int find(vector<int>&nums,int i,bool holding,int count){
        int n=nums.size();
        if(count==2) return 0;
        if(i>=n) return 0;
        if(dp[i][holding][count]!=-1) return dp[i][holding][count];
        if(holding){
            return dp[i][holding][count]=max(nums[i]+find(nums,i+1,false,count+1),find(nums,i+1,true,count));
        }
        else{
            return dp[i][holding][count]=max(find(nums,i+1,true,count)-nums[i],find(nums,i+1,false,count));
        }
    }
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        memset(dp, -1, sizeof(dp)); 
        return find(nums,0,false,0);
    }
};