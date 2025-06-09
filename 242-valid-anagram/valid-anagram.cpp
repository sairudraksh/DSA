class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        int n=s.length();
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        for(int i=0;i<s.length();i++){
            map1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            map2[t[i]]++;
        }
        for(auto x: map1){
            char ch=x.first;
            int freq=x.second;
            if(map2.find(ch)!=map2.end()){
                int freq2=map2[ch];
                if(freq!=freq2) return false;
            }
            else return false;
        }
        return true;
    }
};