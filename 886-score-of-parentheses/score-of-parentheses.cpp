class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        stack<int>st;
        st.push(0);

        for(int i=0;i<n;i++){
            int num=0;

            if(s[i]=='('){
                st.push(0);
            }
            else{
                int num=st.top();
                st.pop();

                if(num==0) num+=1;

                else num*=2;

                st.top()+=num;
            }
        }

        return st.top();
    }
};