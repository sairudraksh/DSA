class Solution {
public:
    int n1;
    int n2;
    vector<vector<int>>dp;
    int find(string &s1,string &s2,int i,int j){
        if(i<=0 || j<=0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1]){
            return dp[i][j]=1+find(s1,s2,i-1,j-1);
        }
        else return dp[i][j]=max(find(s1,s2,i-1,j),find(s1,s2,i,j-1));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        n1=str1.length();
        n2=str2.length();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        int a=find(str1,str2,n1,n2);
        int i=n1;
        int j=n2;
        string ans="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};