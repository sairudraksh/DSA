class Solution {
public:
    int dp[100001];
    bool find(int n){
        if(n<=0) return false;

        int num=(int)sqrt(n);
        if(dp[n]!=-1) return dp[n];
         for(int i=1;i<=num;i++){
            int curr=n-(i*i);
            if(curr<0){
                break;
            }
            bool found=false;
            int l=(int)sqrt(curr);
            for(int j=1;j<=l;j++){
                int currB=curr-(j*j);
                if(currB<0){
                    break;
                }
                bool a=find(currB);
                if(a==false){
                    found=true;
                    dp[currB]=false;
                    break;
                }
            }
            if(found==false){
                return dp[n]=true;
            }
        }
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return find(n);
    }
};