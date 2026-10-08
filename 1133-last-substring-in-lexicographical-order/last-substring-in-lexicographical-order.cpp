class Solution {
public:
    string lastSubstring(string s) {
        string str="";

        int n=s.length();


        char ch='a';
        for(int i=0;i<n;i++){
            if(s[i]>ch) ch=s[i];
        }
        string ans="";
        int idx=0;
        int currIdx=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                if(i!=0 && s[i]==ch && s[i-1]==ch){
                    str+=ch;
                    continue;
                }
                if(str.size()>0){
                    str+=s[i];
                    if(str>ans){
                        ans=str;
                        idx=currIdx;
                    }
                    str=ch;
                    currIdx=i;
                }
                else{
                    currIdx=i;
                    str+=s[i];
                }

            }
            else if(str.size()>0) str+=s[i];
        }

        if(str>ans){
            idx=currIdx;
        }
        string t="";
        for(int i=idx;i<n;i++){
            t+=s[i];
        }
        return t;
    }
};