class Solution {
public:
    vector<vector<int>>dp;
    int ispalindrome(int i,int j,string s){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j] && ispalindrome(i+1,j-1,s)){
            return dp[i][j]=true;
        }
        return dp[i][j]=false;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        dp.resize(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(i,j,s)){
                    count++;
                }
            }
        }
        return count;
    }
};