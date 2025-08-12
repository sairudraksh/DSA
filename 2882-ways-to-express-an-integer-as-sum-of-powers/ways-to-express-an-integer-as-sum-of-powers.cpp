class Solution {
public:
    int MOD = 1e9 + 7; 
    vector<vector<int>>dp;
    int find(int total,int power,int &x){
        if(total==0) return 1;
        int a=pow(power,x);

        if(a>total) return 0;
        else if(total<0) return 0;

        if(dp[total][power]!=-1)  return dp[total][power];

        int l=find(total-a,power+1,x);
        int y=find(total,power+1,x);
        
        return dp[total][power]=(l+y)%MOD;
    }
    int numberOfWays(int n, int x) {
        dp.resize(1000,vector<int>(1000,-1));;
        return find(n,1,x)%MOD;
    }
};