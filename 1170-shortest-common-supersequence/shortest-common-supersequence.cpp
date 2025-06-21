class Solution {
public:
    int find(string &text1,string &text2,int idx1,int idx2,vector<vector<int>>&dp){// use & as it might give tle;
        if(idx1==0 || idx2==0) return 0; // dont put dp[idx1][idx2] here
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1-1]==text2[idx2-1]) {
            return dp[idx1][idx2]=1+find(text1,text2,idx1-1,idx2-1,dp);
        }
        return dp[idx1][idx2]=max(find(text1,text2,idx1-1,idx2,dp),find(text1,text2,idx1,idx2-1,dp));
    }
    
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        int a=find(s1,s2,n,m,dp);
        string ans="";
        int i=n;
        int j=m;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){//upward
                ans+=s1[i-1];
                i--;
            }
            else{
                ans+=s2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=s1[i-1];
            i--;
        }
        while(j>0){
            ans+=s2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};