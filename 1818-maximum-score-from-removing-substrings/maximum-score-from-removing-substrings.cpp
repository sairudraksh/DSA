class Solution {
public:
    string find(string &s,string &maxlen){
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(s[i]==maxlen[1] && !st.empty() && st.top()==maxlen[0]){
                st.pop();
            }
            else st.push(s[i]);
        }

        string ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        int score=0;

        string maxlen="";
        string minlen="";

        if(x > y) {
            maxlen = "ab";
            minlen = "ba";
        } else {
            maxlen = "ba";
            minlen = "ab";
        }

        string new_string1=find(s,maxlen);

        int firstlen=s.length()-new_string1.length();
        score+=(firstlen/2)*max(x,y);

        string new_string2=find(new_string1,minlen);

        int secondlen=new_string1.length()-new_string2.length();
        score+=(secondlen/2)*min(x,y);

        return score;
        
    }
};