class Solution {
public:
    vector<int>dp;
    int find(string &s,int i){
        int n=s.length();
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];
        int a=0;
        int b=0;

        if(s[i]!='0') a=find(s,i+1);
        if(i!=n-1 && s[i]!=0){
            if(s[i]=='1'){
                if(s[i+1]=='1'||s[i+1]=='2'||s[i+1]=='3'||s[i+1]=='4'||s[i+1]=='5'||s[i+1]=='6'|| s[i+1]=='0' || s[i+1]=='7' || s[i+1]=='8' || s[i+1]=='9'){
                    b=find(s,i+2);
                }
            }
            else if(s[i]=='2'){
                if(s[i+1]=='1'||s[i+1]=='2'||s[i+1]=='3'||s[i+1]=='4'||s[i+1]=='5'||s[i+1]=='6'|| s[i+1]=='0'){
                    b=find(s,i+2);
                }
            }
        }

        return dp[i]=a+b;
    }
    int numDecodings(string s) {
        int n=s.length();
        dp.resize(n+1,-1);
        return find(s,0);
    }
};