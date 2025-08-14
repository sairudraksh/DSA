class Solution {
public:
    int minDeletions(string s) {
        int n=s.length();
        vector<int>freq(26,0);

        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        int count=0;

        unordered_set<int>set;

        for(int i=0;i<26;i++){
            while(freq[i]>0 && set.find(freq[i])!=set.end()){
                freq[i]--;
                count++;
            }
            set.insert(freq[i]);
        }
        return count;
    }
};