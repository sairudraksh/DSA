class Solution {
public:
    string toLowerCase(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int num=int(s[i]);
            if(num>=65 && num<=90){
                num=32+num;
                char ch1=char(num);
                ans+=ch1;
            }
            else ans+=s[i];
        }
        return ans;
    }
};