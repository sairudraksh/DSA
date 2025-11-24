class Solution {
public:
    string removeOuterParentheses(string s) {
        int opening=1;
        int closing=0;
        string ans="";
        for(int i=1;i<s.length();i++){
            if(s[i]=='(') opening++;
            else closing++;

            if(opening!=closing){
                ans+=s[i];
            }
            else if(opening==closing){
                i++;
                opening++;
            }
        }
        return ans;
    }
};