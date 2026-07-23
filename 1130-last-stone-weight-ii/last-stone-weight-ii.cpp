class Solution {
public:
    int maximum;
    const int OFFSET=3002;
    int dp[31][6001];
    int find(vector<int>&nums,int i,int sum){
        if(i>=nums.size()){
            if(sum>=0 && sum<maximum){
                maximum=sum;
                return 1;
            }

            return 0;
        }
        
        if(dp[i][sum+OFFSET]!=-1) return dp[i][sum+OFFSET];
        
        bool a=find(nums,i+1,sum+nums[i]);
        bool b=find(nums,i+1,sum-nums[i]);
        
         return dp[i][sum+OFFSET]=a||b;
        
    }
    int lastStoneWeightII(vector<int>& stones) {
        maximum=INT_MAX;
        memset(dp,-1,sizeof(dp));
        find(stones,0,0);
        return maximum;
    }
};