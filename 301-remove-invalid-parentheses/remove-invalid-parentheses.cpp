class Solution {
public:
    int maxlength = 0;
    unordered_set<string> unique; // To remove duplicates
    vector<string> ans;

    void find(string &s, int opening, int closing, int i, string &str) {
        if (i >= s.length()) {
            if (opening == closing) {
                if (str.length() > maxlength) {
                    maxlength = str.length();
                    unique.clear(); // Clear shorter ones
                    unique.insert(str);
                } else if (str.length() == maxlength) {
                    unique.insert(str);
                }
            }
            return;
        }

        if (s[i] != '(' && s[i] != ')') {
            str += s[i];
            find(s, opening, closing, i + 1, str);
            str.pop_back();
            return;
        }        find(s, opening, closing, i + 1, str);

        str += s[i];
        if (s[i] == '(') {
            find(s, opening + 1, closing, i + 1, str);
        } else if (s[i] == ')') {
            if (closing < opening) {
                find(s, opening, closing + 1, i + 1, str);
            }
        }
        str.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
        unique.clear();
        maxlength = 0;

        int opening = 0, closing = 0;
        string str = "";

        find(s, opening, closing, 0, str);

        for (const string& x : unique) {
            ans.push_back(x);
        }

        if (ans.empty()) ans.push_back("");
        return ans;
    }
};
