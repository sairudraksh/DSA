class Solution {
public:
    int maxans=INT_MAX;
    vector<int>dp;
    bool ispalindrome(string &ans){
        if(ans.length()==1) return true;
        int i=0;
        int j=ans.length()-1;
        while(i<=j){
            if(ans[i]!=ans[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int find(string &s,int &n,int i){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        string ans1="";
        int result=INT_MAX;
        for(int k=i;k<n;k++){
            ans1+=s[k];
            if(ispalindrome(ans1)==true){
                int a=1+find(s,n,k+1);
                result=min(a,result);
            }
        }
        return dp[i]=result;
        
    }
    int minCut(string s) {
        int n=s.length();
        dp.resize(n+1,-1);
        int count=0;
        return find(s,n,0)-1;
    }
};