class Solution {
public:
    int dp[10001][7][7];
    long long mod=1e9+7;
    int find(int &n,int prev,int morePrev,int count){
        if(count==n) return 1;
        long long ans=0;
        if(dp[count][prev][morePrev]!=-1) return dp[count][prev][morePrev];
        if(count==0){
            for(int i=1;i<=6;i++){
                ans+=find(n,i,0,count+1)%mod;
            }
        }
        else{
            for(int i=1;i<=6;i++){
                if(morePrev!=i && prev!=i){
                    if(prev==1){
                        ans+=find(n,i,prev,count+1)%mod;
                    }
                    if(prev==2 && (i==1 || i==3 || i==5)){
                        ans+=find(n,i,prev,count+1)%mod;
                    }
                    if(prev==3 && (i==1 || i==2 || i==4 || i==5)){
                        ans+=find(n,i,prev,count+1)%mod;
                    }
                    if(prev==4 && (i==1 || i==3 || i==5)){
                        ans+=find(n,i,prev,count+1)%mod;
                    }
                    if(prev==5 && (i==1 || i==2 || i==6 || i==3 || i==4)){
                        ans+=find(n,i,prev,count+1)%mod;
                    }
                    if(prev==6 && (i==1 || i==5)){
                        ans+=find(n,i,prev,count+1)%mod;
                    }
                }
            }
        }
        return dp[count][prev][morePrev]=ans%mod;
    }
    int distinctSequences(int n) {
        memset(dp,-1,sizeof(dp));
        return find(n,0,0,0)%mod;
    }
};