class Solution {
public:
    string reverseWords(string s) {
        int j=s.length()-1;
        int i=0;

        while(s[i]==' '){
            i++;
        }
        while(s[j]==' '){
            j--;
        }
        string ans="";
        while(j>=i){
            string str="";

            while(j>=i && s[j]!=' '){
                str=s[j]+str;
                j--;
            }

            while(j>=i && s[j]==' '){
                j--;
            }
            if(j>=i) ans+=(str+" ");
            else ans+=str;
        }
        return ans;
    }
};