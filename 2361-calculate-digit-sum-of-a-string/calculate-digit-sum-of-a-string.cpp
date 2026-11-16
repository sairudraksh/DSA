class Solution {
public:
    string digitSum(string s, int k) {
        if(s.length()<=k) return s;
        int n=s.length();
        int i=0;
        string ans="";
        while(i<s.length()){
            int num=0;
            int j=i;
            for(;j<min(n,i+k);j++){
                char ch=s[j];
                int num1=ch-'0';
                num+=num1;
            }
            i=j;
            string str=to_string(num);

            ans+=str;
        }
        return digitSum(ans,k);
    }
};