class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>map;
        int count=0;
        int start=0;
        int end=0;
        int n=s.size();
        while(end<n){
            map[s[end]]++;
            while(map['a'] && map['b'] && map['c']){
                count=count+(n-end);
                map[s[start]]--;
                start++;
            }
            end++;
        }
        return count;
    }
};