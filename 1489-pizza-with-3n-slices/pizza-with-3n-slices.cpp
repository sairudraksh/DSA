class Solution {
public:
    int n;
    int dp[501][2][200];
    int find(vector<int>&nums,int i,bool taken,int count){
        if(i>=n) return 0;
        if(count==n/3) return 0;
        if(dp[i][taken][count]!=-1) return dp[i][taken][count];
        if(i==n-1){
            if(taken){
                return dp[i][taken][count]=find(nums,i+1,taken,count);
            }
            else{
                return dp[i][taken][count]=max(find(nums,i+1,taken,count),nums[i]+find(nums,i+2,taken,count+1));
            }
        }
        else if(i==0){
            return dp[i][taken][count]=max(nums[i]+find(nums,i+2,true,count+1),find(nums,i+1,false,count));
        }
        else return dp[i][taken][count]=max(nums[i]+find(nums,i+2,taken,count+1),find(nums,i+1,taken,count));
    }
    int maxSizeSlices(vector<int>& slices) {
        n=slices.size();
        memset(dp,-1,sizeof(dp));
        return find(slices,0,false,0);
    }
};