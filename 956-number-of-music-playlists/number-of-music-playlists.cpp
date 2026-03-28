class Solution {
public:
    int dp[101][101];
    long long mod=1e9+7;
    long long find(int &n,int &goal,int &k,int count ,int unique){
        if(count==goal){
            if(unique==n) return 1;
            return 0;
        }
        if(dp[count][unique]!=-1) return dp[count][unique];
        long long result=0;
        if(n-unique>0){
            (result+=find(n,goal,k,count+1,unique+1)%mod*(n-unique)%mod)%mod;
        }
        if(unique-k>0){
            (result+=find(n,goal,k,count+1,unique)%mod*(unique-k)%mod)%mod;
        }
        return dp[count][unique]=result;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        return find(n,goal,k,0,0)%mod;
    }
};