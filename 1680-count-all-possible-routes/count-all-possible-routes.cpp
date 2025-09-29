class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    vector<vector<int>>dp;
    int find(vector<int>& nums,int start,int finish,int fuel,int leftFuel,int idx){
        if (leftFuel < 0) return 0;
        long long total=0;
        if(idx==finish) total++;

        if(dp[idx][leftFuel]!=-1) return dp[idx][leftFuel];
        for(int k=0;k<n;k++){
            if(k==idx) continue;

            if(abs(nums[k]-nums[idx])<=leftFuel){
                total+=find(nums,start,finish,fuel,leftFuel-(abs(nums[k]-nums[idx])),k);
            }
        }
        return dp[idx][leftFuel]=total%MOD;
    }
    int countRoutes(vector<int>& nums, int start, int finish, int fuel) {
        n=nums.size();
        dp.resize(n+1,vector<int>(fuel+1,-1));
        return find(nums,start,finish,fuel,fuel,start)%MOD;
    }
};