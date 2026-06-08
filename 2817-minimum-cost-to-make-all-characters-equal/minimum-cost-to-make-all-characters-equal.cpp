class Solution {
public:
    long long minimumCost(string s) {
        int n=s.length();
        vector<long long>dp1(n,0);
        vector<long long>dp2(n,0);

        for(int i=1;i<s.length();i++){
            if(s[i]!=s[i-1]){
                dp1[i]=dp1[i-1]+i;
            }
            else dp1[i]=dp1[i-1];
        }

        for(int i=s.length()-2;i>=0;i--){
            if(s[i]!=s[i+1]){
                dp2[i]=dp2[i+1]+(n-(i+1));
            }
            else dp2[i]=dp2[i+1];
        }
        long long minimum=LLONG_MAX;
        for(int i=0;i<n;i++){
            minimum=min(minimum,dp1[i]+dp2[i]);
        }
        return minimum;
    }
};