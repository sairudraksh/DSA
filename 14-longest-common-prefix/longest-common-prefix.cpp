class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        if(strs.size()==1){
            return strs[0];
        }
        string s1=strs[0];
        string s2=strs[strs.size()-1];
        string ans="";
        for(int i=0;i<min(s1.length(),s2.length());i++){
            if(s1[i]==s2[i]) ans+=s1[i];
            else return ans;
        }
        return ans;
    }
};