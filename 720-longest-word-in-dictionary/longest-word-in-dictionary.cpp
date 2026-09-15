class Solution {
public:
    string longestWord(vector<string>& words) {
        int n=words.size();

        sort(words.begin(),words.end());

        unordered_set<string>st;
        string ans="";
        for(int i=0;i<n;i++){
            string s=words[i];
            s.pop_back();

            if(words[i].length()==1 || st.count(s)){
                st.insert(words[i]);

                if(s.length()+1>ans.length()){
                    ans=words[i];
                }
            }
        }
        return ans;
    }
};