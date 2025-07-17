class Solution {
public:
    vector<vector<int>>dp;
    bool ispalindrome(string  &s,int i,int j){
        int k=i;
        int l=j;
        if(dp[i][j]!=-1) return dp[i][j];
        while(i<=j){
            if(s[i]!=s[j]) break;
            i++;
            j--;
        }
        if(i<j) return dp[k][l]=false; 
        return dp[k][l]=true;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        int maxlen=0;
        int sp=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(s,i,j)){
                    if (j-i+1>maxlen) {
                        maxlen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};