class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(string &s1,string &s2,int i,int j){
        if(i>=n && j>=m) return 0;
        if(i>=n){
            return m-j;
        }
        if(j>=m){
            return n-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            int a=find(s1,s2,i+1,j+1);
            return dp[i][j]=a;
        }
        else{
            int a=find(s1,s2,i+1,j);
            int b=find(s1,s2,i,j+1);
            if(a==INT_MAX && b==INT_MAX) return dp[i][j]=INT_MAX;
            else return dp[i][j]=1+min(a,b);
        }
    }
    int minDistance(string word1, string word2) {
        n=word1.length();
        m=word2.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(word1,word2,0,0);
    }
};