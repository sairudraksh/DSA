class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            char ch=t[i];
            if(map.find(ch)==map.end()) return ch;
            map[ch]--;
            if(map[ch]==0) map.erase(ch);
        }
        return 'a';
    }
};