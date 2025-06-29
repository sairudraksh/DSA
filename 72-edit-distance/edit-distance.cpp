class Solution {
public:
    int find(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i==-1 && j==-1) return 0;
        else if(i==-1 && j!=-1){
            return j+1;
        }
        else if(j==-1 && i!=-1){
            return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=find(s1,s2,i-1,j-1,dp);
        }
        return dp[i][j]=1+min({find(s1,s2,i,j-1,dp),find(s1,s2,i-1,j,dp),find(s1,s2,i-1,j-1,dp)});
    }
    int minDistance(string word1, string word2) {
        int i=word1.length()-1;
        int j=word2.length()-1;
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return find(word1,word2,i,j,dp);
    }
};