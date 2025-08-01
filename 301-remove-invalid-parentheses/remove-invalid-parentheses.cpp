class Solution {
public:
    unordered_set<string> set;
    int maxLength = 0;

    void find(string &s, int i, int &opening, int &closing, string &str) {
        if (i == s.length()) {
            if (opening == closing) {
                if (str.length() >= maxLength) {
                    if (str.length() > maxLength) {
                        set.clear();
                        maxLength = str.length();
                    }
                    set.insert(str);
                }
            }
            return;
        }

        char ch = s[i];

        if (ch != '(' && ch != ')') {
            // Always include non-parenthesis characters
            str.push_back(ch);
            find(s, i + 1, opening, closing, str);
            str.pop_back(); // backtrack
        } 
        else {
            // Exclude the parenthesis
            find(s, i + 1, opening, closing, str);

            if (ch == '(') {
                opening++;
                str.push_back('(');
                find(s, i + 1, opening, closing, str);
                str.pop_back();
                opening--; // backtrack
            } 
            else if (ch == ')') {
                if (closing < opening) {
                    closing++;
                    str.push_back(')');
                    find(s, i + 1, opening, closing, str);
                    str.pop_back();
                    closing--; // backtrack
                }
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int opening = 0, closing = 0;
        string str = "";
        find(s, 0, opening, closing, str);

        if (set.empty()) return {""};

        return vector<string>(set.begin(), set.end());
    }
};
