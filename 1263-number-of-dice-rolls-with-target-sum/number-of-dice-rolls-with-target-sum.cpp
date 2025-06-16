#define mod 1000000007
class Solution {
public:
    vector<vector<int>>dp;
    int find(int n,int k,int target){
        if(n==0 && target==0) return 1;
        if(n==0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int sum=0;
        for(int i=1;i<=k;i++){
            if(i>target) continue;
            sum=((sum%mod)+find(n-1,k,target-i)%mod)%mod;
        }
        return dp[n][target]=sum%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(35, vector<int>(1001,-1));
        int a=find(n,k,target);
        return a;
    }
};