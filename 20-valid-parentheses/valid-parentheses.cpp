class Solution {
public:
    bool isValid(string s) {
        int n=s.length(); 
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];

            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;

                char ch1=st.top();
                st.pop();

                if(ch1=='(' && ch!=')') return false;
                else if(ch1=='{' && ch!='}') return false;
                else if(ch1=='[' && ch!=']') return false;
            }
        }
        return st.empty();
    }
};