class Solution {
public:
    long long dp[100001][3][2];
    long long mod=1e9+7;
    long long find(int a,int l,int count,int &n){
        if(a>=2) return 0;
        if(count==n) return 1;
        if(dp[count][l][a]!=-1) return dp[count][l][a];
        if(l==2){
            return dp[count][l][a]=(find(a+1,0,count+1,n)%mod+find(a,0,count+1,n)%mod)%mod;
        }
        else{
            return dp[count][l][a]=(find(a+1,0,count+1,n)%mod+find(a,l+1,count+1,n)%mod+find(a,0,count+1,n)%mod)%mod;
        }
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,0,n)%mod;
    }
};