class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    bool find(string &s,string &p,int i,int j){
        if(j>=m){
            if(i>=n) return true;
            return false;
        }
        bool isTrue=false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<n){
            if(s[i]==p[j] || p[j]=='.'){
                isTrue=true;
            }
        }
        bool ans=false;
        if(j+1<m && p[j+1]=='*'){
            if(find(s,p,i,j+2)) return dp[i][j]=true;
            else{
                if(isTrue){
                    if(find(s,p,i+1,j)) return dp[i][j]=true;
                }
            }
        }
        else{
            if(isTrue){
                if(find(s,p,i+1,j+1)) return dp[i][j]=true;
            }
        }


        return dp[i][j]=false;

    }
    bool isMatch(string s, string p) {
        n=s.length();
        m=p.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(s,p,0,0);
    }
};