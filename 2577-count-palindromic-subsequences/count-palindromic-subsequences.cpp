#define ll long long
class Solution {
public:
    long long mod;
    ll dp[10001][11][11][6];
    long long find(int idx,int first,int second,int i,string &s){
        if(i==5) return 1;
        if(idx>=s.length()) return 0;
        long long a=0;
        if(dp[idx][first][second][i]!=-1) return dp[idx][first][second][i];
        a+=find(idx+1,first,second,i,s);
        if(i==0){
            a+=find(idx+1,s[idx]-'0',second,i+1,s);
            a%=mod;
        }
        else if(i==1){
            a+=find(idx+1,first,s[idx]-'0',i+1,s);
            a%=mod;
        }
        else if(i==2){
            a+=find(idx+1,first,second,i+1,s);
            a%=mod;
        }
        else if(i==3){
            if(s[idx]-'0'==second) a+=find(idx+1,first,second,i+1,s);
            a%=mod;
        }
        else if(i==4){
            if(s[idx]-'0'==first) a+=find(idx+1,first,second,i+1,s);
            a%=mod;
        }
        return dp[idx][first][second][i]=a;
    }
    int countPalindromes(string s){
        memset(dp,-1,sizeof dp);
        mod=1e9+7;
        return find(0,0,0,0,s);
    }
};