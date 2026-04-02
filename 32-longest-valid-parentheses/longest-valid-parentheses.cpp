class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<int>st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty() && s[st.top()]=='('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }

        if(st.size()==0) return n;
        int ans=0;
        int len=n;
        while(st.size()>0){
            int num=st.top();

            ans=max(ans,len-num-1);
            len=num;
            st.pop();

        }

        return max(ans,len);

    }
};