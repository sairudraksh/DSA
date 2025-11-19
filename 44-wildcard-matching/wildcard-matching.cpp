class Solution {
public:
    int n1;
    int n2;
    vector<vector<int>>dp;
    bool find(string &s1,string &s2,int i,int j){
        if(i>=n1){
            while(j<n2 && s2[j]=='*') j++;
        }
        if(j>=n2){
            while(i<n2 && s2[j]=='*') i++;
        }
        if(i>=n1 && j>=n2) return true;
        if(i>=n1 || j>=n2) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]=='*' || s2[j]=='*'){
            return dp[i][j]=find(s1,s2,i+1,j) ||find(s1,s2,i+1,j+1) ||find(s1,s2,i,j+1);
        }
        else if(s1[i]==s2[j] || s1[i]=='?' || s2[j]=='?'){
            return dp[i][j]=find(s1,s2,i+1,j+1);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s1, string s2) {
        n1=s1.length();
        n2=s2.length();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        return find(s1,s2,0,0);
    }
};