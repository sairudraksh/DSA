class Solution {
public:
    int minPartitions(string s) {
        int maxans=0;

        for(int i=0;i<s.length();i++){
            maxans=max(maxans,s[i]-'0');
        }
        return maxans;
    }
};