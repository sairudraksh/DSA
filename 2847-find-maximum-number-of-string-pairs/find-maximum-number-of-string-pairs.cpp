class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        unordered_set<string>st;
        for(int i=0;i<n;i++){
            st.insert(words[i]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            string s=words[i];
            reverse(s.begin(),s.end());
            if(words[i]==s) continue;
            if(st.find(s)!=st.end()){
                count++;
                st.erase(words[i]);
            }
        }
        return count;
    }
};