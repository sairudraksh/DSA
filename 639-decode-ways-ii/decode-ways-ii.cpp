class Solution {
public:
    long long mod=1e9+7;
    vector<int>dp;
    long long find(string &s,int i){
        if(i>=s.length()) return 1;

        long long sum=0;

        if(dp[i]!=-1) return dp[i];

        if(s[i]=='0') return dp[i]=0;

        if(s[i]!='*'){
            sum+=1*find(s,i+1)%mod;
            if(i!=s.length()-1 && s[i+1]=='*'){
                if(s[i]=='1'){
                    sum+=(9LL*find(s,i+2))%mod;
                }
                else if(s[i]=='2'){
                    sum+=(6LL*find(s,i+2))%mod;
                }
            }
            else if(i!=s.length()-1){
                int num=(s[i]-'0')*10+(s[i+1]-'0');
                if(num>=10 && num<=26){
                    sum+=(find(s,i+2))%mod;
                }
            }
        }
        else{
            sum+=(9*find(s,i+1))%mod;
            if(i!=s.length()-1 && s[i+1]=='*'){
                sum+=((15LL)*find(s,i+2))%mod;
            }
            else{
                if(i!=s.length()-1 && (s[i+1]=='1' || s[i+1]=='2' ||s[i+1]=='3' ||s[i+1]=='4' ||s[i+1]=='5' ||s[i+1]=='6' || s[i+1]=='0')){
                    sum+=(2LL*find(s,i+2))%mod;
                }
                else if(i!=s.length()-1){
                    sum+=(find(s,i+2))%mod;
                }
            }
        }
        return dp[i]=sum%mod;
    }
    int numDecodings(string s) {
        dp.resize(s.length()+1,-1);
        return find(s,0)%mod;
    }
};