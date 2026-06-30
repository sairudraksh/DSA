class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<int,int>map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        int ans=s.length();
        for(int i=0;i<s.length();i++){
            if(map[s[i]]<k){
                int left=longestSubstring(s.substr(0,i),k);
                int right=longestSubstring(s.substr(i+1),k);
                return max(left,right);
            }
        }
        return ans;
    }
};