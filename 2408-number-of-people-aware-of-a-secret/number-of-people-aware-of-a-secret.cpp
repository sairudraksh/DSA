class Solution {
public:
    vector<vector<int>>dp;
    const int MOD = 1e9+7;
    int find(int &n,int &delay,int &forget,int curr,int st){
        if(curr>n) return 0;
        int b=0;
        if(curr-st>=forget) return 0;
        if(dp[curr][st]!=-1) return dp[curr][st];
        int a=find(n,delay,forget,curr+1,st);

        if(curr-st>=delay){
            if(n-curr>=forget){
                b=find(n,delay,forget,curr+1,curr);
            }
            else b=1+find(n,delay,forget,curr+1,curr);
        }
        return dp[curr][st]=(a+b)%MOD;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        dp.resize(n+2,vector<int>(n+2,-1));
        if(n-1>=forget){
            return find(n,delay,forget,1,1)%MOD;
        }
        else return 1+find(n,delay,forget,1,1)%MOD;
    }
};