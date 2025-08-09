class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening=0;
        int closing=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') opening++;
            else closing++;
            if(closing>opening){
                count++;
                opening++;
            }
        }
        return count+(opening-closing);
    }
};