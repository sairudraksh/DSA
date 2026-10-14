class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        long long orgsum=sum;
        while(sum>=9 && num>=1){
            ans+='9';
            sum-=9;
            num--;
        }
        while(sum>=8 && num>=1){
            ans+='8';
            sum-=8;
            num--;
        }
        while(sum>=7 && num>=1){
            ans+='7';
            sum-=7;
            num--;
        }
        while(sum>=6 && num>=1){
            ans+='6';
            sum-=6;
            num--;
        }
        while(sum>=5 && num>=1){
            ans+='5';
            sum-=5;
            num--;
        }
        while(sum>=4 && num>=1){
            ans+='4';
            sum-=4;
            num--;
        }
        while(sum>=3 && num>=1){
            ans+='3';
            sum-=3;
            num--;
        }
        while(sum>=2 && num>=1){
            ans+='2';
            sum-=2;
            num--;
        }
        while(sum>=1 && num>=1){
            ans+='1';
            sum-=1;
            num--;
        }
        string s=ans;
        while(num>=1){
            s+='0';
            num--;
        }
        long long t=0;
        int i=ans.size()-1;
        while(i>=0){
            int num=ans[i]-'0';
            t+=num;
            i--;
        }
        if(t!=orgsum) return "";
        return s;
    }
};