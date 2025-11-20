class Solution {
public:
    int n;
    vector<int>dp;
    bool isPalindrome(string &s){
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int find(string &s,int i){
        if(i>=n) return 0;
        string ans="";

        int a=INT_MAX;
        if(dp[i]!=-1) return dp[i];
        for(int k=i;k<n;k++){
            ans+=s[k];
            if(isPalindrome(ans)){
                int b=1+find(s,k+1);
                a=min(a,b);
            }
        }
        return dp[i]=a;
    }
    int minCut(string s) {
        n=s.length();
        if(n==1) return 0;
        dp.resize(n+1,-1);
        int a=find(s,0);
        return a-1;
    }
};