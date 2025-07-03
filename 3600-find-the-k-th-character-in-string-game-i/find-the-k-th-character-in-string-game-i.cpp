class Solution {
public:
    string find(string ans) {
        string s="";
        for(int i=0;i<ans.length();i++) {
            char next=(ans[i]-'a'+1)%26+'a';
            s+=next;
        }
        return s;
    }
    char kthCharacter(int k) {
        string ans="a";
        for(int i=0;i<500;i++){
            string s=find(ans);
            ans+=s;
            if(ans.length()>k) break;
        }
        return ans[k-1];
    }
};