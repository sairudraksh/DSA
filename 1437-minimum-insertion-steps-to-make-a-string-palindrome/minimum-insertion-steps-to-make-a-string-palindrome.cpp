class Solution {
public:
    vector<vector<int>>dp;
    int find(string &s1,string &s2,int i,int j,int &n1,int &n2){
        if(i>=n1 || j>=n2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+find(s1,s2,i+1,j+1,n1,n2);
        }
        return dp[i][j]=max(find(s1,s2,i+1,j,n1,n2),find(s1,s2,i,j+1,n1,n2));
    }
    int minInsertions(string s1) {
        int n1=s1.length();
        string s2=s1;
        reverse(s2.begin(),s2.end());
        int n2=s2.length();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        int a=find(s1,s2,0,0,n1,n2);
        return s1.length()-a;
    }
};