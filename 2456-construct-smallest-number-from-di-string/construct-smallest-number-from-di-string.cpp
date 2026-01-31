class Solution {
public:
    //ans += char('0' + st.top());
    string smallestNumber(string s) {
        int n=s.length();
        int num=1;
        stack<int>st;
        string ans="";
        for(int i=0;i<s.length();i++){
            st.push(num++);
            if(s[i]=='I'){
                while(!st.empty()){
                    ans+=char('0'+st.top());
                    st.pop();
                }
            }
        }

        st.push(num);

        while(st.size()>0){
            ans+=char('0'+st.top());
            st.pop();
        }
        return ans;
    }
};