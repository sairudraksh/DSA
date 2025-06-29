class Solution {
public:
    vector<vector<int>>dp;
    int find(string &s1,string &s2,int &n1,int &n2,int i,int j){
        if(j>=n2) return 1;
        if(i>=n1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=find(s1,s2,n1,n2,i+1,j+1)+find(s1,s2,n1,n2,i+1,j);
        }
        else return dp[i][j]=find(s1,s2,n1,n2,i+1,j);
    }
    int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        return find(s,t,n1,n2,0,0);
    }
};