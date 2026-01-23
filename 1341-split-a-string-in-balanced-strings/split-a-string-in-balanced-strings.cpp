class Solution {
public:
    int balancedStringSplit(string s) {
        int rcount=0;
        int lcount=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='L') lcount++;
            else rcount++;
            if(lcount==rcount) count++;
        }
        return count;
    }
};