class Solution {
public:
    string processStr(string s) {
        int n=s.length();
        string result="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='*' && s[i]!='#' && s[i]!='%'){
                result+=s[i];
            }
            else if(s[i]=='*' && result.length()!=0){
                result.pop_back();
            }
            else if(s[i]=='#'){
                result+=result;
            }
            else reverse(result.begin(),result.end());
        }
        return result;
    }
};