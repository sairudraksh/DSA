class Solution {
public:
    unordered_map<string, int> map;
    vector<string> finalans;

    void find(string str, vector<string>& wordDict, int i, int j, string &s) {
        if (j > str.size()) return;

        string s1 = str.substr(i, j - i);

        if (map.find(s1) != map.end()) {
            string old = s;

            if (!s.empty() && s.back() != ' ') s += " ";
            s += s1;

            if (j == str.size()) {
                finalans.push_back(s);
            } else {
                find(str, wordDict, j, j, s);
            }

            s = old; // backtrack
        }

        // continue expanding the word
        find(str, wordDict, i, j + 1, s);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++) {
            map[wordDict[i]]++;
        }
        string s1 = "";
        find(s, wordDict, 0, 0, s1);
        return finalans;
    }
};
