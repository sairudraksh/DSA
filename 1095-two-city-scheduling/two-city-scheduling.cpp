class Solution {
public:
    int n;
    int dp[105][55][55];
    int find(vector<vector<int>>& nums,int i,int acount,int bcount){
        if(i==n-1){
            if(acount==nums.size()/2){
                return nums[i][1];
            }
            return nums[i][0];
        } 
        if(dp[i][acount][bcount]!=-1) return dp[i][acount][bcount];
        if(acount!=n/2 && bcount!=n/2){
            return dp[i][acount][bcount]=min(nums[i][0]+find(nums,i+1,acount+1,bcount),nums[i][1]+find(nums,i+1,acount,bcount+1));
        }
        else{
            if(acount==nums.size()/2){
                return dp[i][acount][bcount]=nums[i][1]+find(nums,i+1,acount,bcount+1);

            }
            return dp[i][acount][bcount]=nums[i][0]+find(nums,i+1,acount+1,bcount);
        }
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        n=costs.size();
        memset(dp, -1, sizeof(dp));
        return find(costs,0,0,0);
    }
};