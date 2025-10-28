class Solution {
public:
    vector<vector<int>>dp;
    int find(string &s1,string &s2,int i,int j){
        if(i>=s1.length() && j>=s2.length()) return 0;
        else if(j>=s2.length()){
            return s1.length()-i;
        }
        else if(i>=s1.length()){
            return s2.length()-j;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=find(s1,s2,i+1,j+1);
        }
        else{
            return dp[i][j]=1+min(find(s1,s2,i+1,j),find(s1,s2,i,j+1));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(word1,word2,0,0);
    }
};