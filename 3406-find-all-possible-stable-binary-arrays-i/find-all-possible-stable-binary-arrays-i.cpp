class Solution {
public:
    int dp[201][201][2];
    int MOD=1e9+7;
    int find(int zeroLeft,int oneLeft,bool PrevwasOne,int &limit){

        if(zeroLeft==0 && oneLeft==0) return 1;

        int result=0;

        if(dp[zeroLeft][oneLeft][PrevwasOne]!=-1) return dp[zeroLeft][oneLeft][PrevwasOne];

        if(PrevwasOne==true){
            for(int i=1;i<=min(limit,zeroLeft);i++){
                result=(result+find(zeroLeft-i,oneLeft,false,limit))%MOD;
            }
        }
        else{
            for(int i=1;i<=min(limit,oneLeft);i++){
                result=(result+find(zeroLeft,oneLeft-i,true,limit))%MOD;
            }
        }

        return dp[zeroLeft][oneLeft][PrevwasOne]=result%MOD;

    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int startWithzero=find(zero,one,true,limit);
        int startWithone=find(zero,one,false,limit);
        return (startWithzero+startWithone)%MOD;
    }
};