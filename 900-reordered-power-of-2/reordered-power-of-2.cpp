class Solution {
public:
    bool isPower(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    
    bool find(const string& s, string& ans, vector<bool>& used) {
        if (ans.length() == s.length()) {
            int t = stoi(ans);
            return isPower(t);
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (used[i]) continue;
            if (ans.length() == 0 && s[i] == '0') continue; // Skip leading zero
            
            used[i] = true;
            ans.push_back(s[i]);
            
            if (find(s, ans, used)) return true;
            
            ans.pop_back();
            used[i] = false;
        }
        return false;
    }
    
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        vector<bool> used(s.length(), false);
        string ans = "";
        return find(s, ans, used);
    }
};
