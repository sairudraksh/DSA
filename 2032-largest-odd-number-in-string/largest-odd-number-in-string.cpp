class Solution {
public:
    string largestOddNumber(string s) {
        int n=s.length();

        int idx=-1;
        for(int i=n-1;i>=0;i--){
            int num=(int)s[i];
            if(num%2!=0){
                idx=i;
                break;
            }
        }
        if(idx==-1) return "";
        string ans="";
        for(int i=0;i<=idx;i++){
            ans+=s[i];
        }
        return ans;
    }
};