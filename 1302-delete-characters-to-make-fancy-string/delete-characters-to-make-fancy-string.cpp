class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int count=0;
        for(int i=0;i<s.size();i++){
            if(i==0 || s[i]!=s[i-1]){
                ans+=s[i];
                count=0;
                count++;
            }
            else if(s[i]==s[i-1] && count<2){
                ans+=s[i];
                count++;
            }
        }
        return ans;
    }
};