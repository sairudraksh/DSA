class Solution {
public:
    int n;
    vector<string> v;

    bool isValid(string &s) {
        if (s.empty()) return false;
        if (s.length() > 1 && s[0] == '0') return false;
        if (s.length() > 3) return false;

        int x = stoi(s);
        return x >= 0 && x <= 255;
    }

    void find(string &s, string &str, string &ans, int i, int dot) {
        if (i == n) {
            if (dot == 3 && isValid(str)){
                ans += str;
                v.push_back(ans);
            }
            return;
        }

        // take current digit
        str.push_back(s[i]);

        // continue current segment
        if (isValid(str)) {
            find(s, str, ans, i + 1, dot);
        }

        // cut segment here (add dot)
        if (isValid(str) && dot < 3) {
            string oldStr = str;
            string oldAns = ans;

            ans += str + ".";
            str = "";
            find(s, str, ans, i + 1, dot + 1);

            str = oldStr;
            ans = oldAns;
        }

        str.pop_back();
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        string ans = "";
        string str = "";
        find(s, str, ans, 0, 0);
        return v;
    }
};