class Solution {
public:
    string s1;
    string s2;
    string t;
    int MOD=1e9+7;
    long long dp[101][101][101][2][2];
    long long find(int i,int j,int k,int taken1,int taken2){
        if(k>=t.length()){
            if(taken1 && taken2) return 1;
            else return 0;
        }

        if(dp[i][j][k][taken1][taken2]!=-1) return dp[i][j][k][taken1][taken2];

        long long res=0;

        for(int l=i;l<s1.length();l++){
            if(s1[l]==t[k]){
                res=res+find(l+1,j,k+1,true,taken2)%MOD;
            }
        }

        for(int l=j;l<s2.length();l++){
            if(s2[l]==t[k]){
                res=res+find(i,l+1,k+1,taken1,true)%MOD;
            }
        }

        return dp[i][j][k][taken1][taken2]=res%MOD;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        s1=word1;
        s2=word2;
        t=target;
        memset(dp,-1,sizeof(dp));
        return find(0,0,0,false,false);
    }
};
