class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char, string> mp;
        set<string>st;
        mp['a'] = ".-";
        mp['b'] = "-...";
        mp['c'] = "-.-.";
        mp['d'] = "-..";
        mp['e'] = ".";
        mp['f'] = "..-.";
        mp['g'] = "--.";
        mp['h'] = "....";
        mp['i'] = "..";
        mp['j'] = ".---";
        mp['k'] = "-.-";
        mp['l'] = ".-..";
        mp['m'] = "--";
        mp['n'] = "-.";
        mp['o'] = "---";
        mp['p'] = ".--.";
        mp['q'] = "--.-";
        mp['r'] = ".-.";
        mp['s'] = "...";
        mp['t'] = "-";
        mp['u'] = "..-";
        mp['v'] = "...-";
        mp['w'] = ".--";
        mp['x'] = "-..-";
        mp['y'] = "-.--";
        mp['z'] = "--..";

        for(int i=0;i<words.size();i++){
            string s=words[i];

            string ans="";
            for(int j=0;j<s.length();j++){
                ans+=mp[s[j]];
            }
            st.insert(ans);
        }
        return st.size();

    }
};