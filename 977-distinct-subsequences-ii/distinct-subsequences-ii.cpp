class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.length();
        vector<int>dp(n+1,0);
        int mod=1e9+7;
        dp[0]=1;

        vector<int>freq(26,0);

        for(int i=1;i<=n;i++){
            char ch=s[i-1];

            dp[i]=(dp[i-1]*2)%mod;

            if(freq[ch-'a']!=0) dp[i]=(dp[i]-freq[ch-'a']+mod)%mod;

            freq[ch-'a']=dp[i-1];
        }
        return (dp[n]-1+mod)%mod;
    }
};