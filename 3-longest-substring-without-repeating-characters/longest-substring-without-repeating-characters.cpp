class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>map;

        int n=s.length();

        int i=0;
        int j=0;
        int len=0;
        int maxlen=0;
        while(j<n){
            map[s[j]]++;
            while(map[s[j]]>1){
                map[s[i]]--;
                i++;
            }
            len=j-i+1;
            maxlen=max(maxlen,len);
            j++;

        }
        return maxlen;
    }
};