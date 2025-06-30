class Solution {
public:
    vector<vector<int>>dp;
    int find(string &s1,string &s2,int &n1,int &n2,int i,int j){
        if(i>=n1){
            return (n2-j);
        }
        if(j>=n2){
            return (n1-i);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=find(s1,s2,n1,n2,i+1,j+1);
        }
        else return dp[i][j]=min(1+find(s1,s2,n1,n2,i+1,j),1+find(s1,s2,n1,n2,i,j+1));
    }
    int minDistance(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        return find(s1,s2,n1,n2,0,0);
    }
};