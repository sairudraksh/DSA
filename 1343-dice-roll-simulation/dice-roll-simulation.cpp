class Solution {
public:
    int mod=1e9+7;
    int dp[5001][16][7];
    long long find(vector<int>&rollMax,int &n,int count,int streak,int num){
        if(count==n) return 1;
        if(dp[count][streak][num]!=-1) return dp[count][streak][num];
        long long ans=0;
        for(int i=1;i<=6;i++){
            if(i==num){
                if(streak<rollMax[num-1]) ans+=find(rollMax,n,count+1,streak+1,num)%mod;
            }
            else{
                ans+=find(rollMax,n,count+1,1,i)%mod;
            }
        }
        return dp[count][streak][num]=ans%mod;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return find(rollMax,n,0,0,0)%mod;
    }
};