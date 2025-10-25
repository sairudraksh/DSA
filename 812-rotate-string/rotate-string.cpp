class Solution {
public:
    bool rotateString(string s, string s2) {
        if(s.length()!=s2.length()) return false;
        string s1=s+s;

        for(int i=0;i<s1.length();i++){
            int j=0;
            int l=i;
            if(s1[l]==s2[j]){
                while(j<s2.length()){
                    if(s1[l]!=s2[j]) break;
                    l++;
                    j++;
                }
                if(j==s2.length()) return true;
            }
        }

        return false;
    }
};