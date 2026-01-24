class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string str="";

        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                reverse(str.begin(),str.end());
                ans+=str;
                str="";
                ans+=' ';
            }
            else str+=s[i];
        }
        if(str.length()==0){
            ans.pop_back();
            return ans;
        }
        reverse(str.begin(),str.end());
        ans+=str;
        return ans;
    }
};