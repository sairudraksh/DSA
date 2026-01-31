class Solution {
public:
    vector<int> diStringMatch(string s) {
        int num=0;
        stack<int>st;
        vector<int>v;

        for(int i=0;i<s.length();i++){
            st.push(num++);
            if(s[i]=='I'){
                while(st.size()>0){
                    v.push_back(st.top());
                    st.pop();
                }
            }
        }

        st.push(num);
        while(st.size()>0){
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
};