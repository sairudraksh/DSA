class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.length();
        stack<char>st;

        for(int i=0;i<n;i++){
            char ch=s[i];

            int num=ch-'0';

            while(st.size()>0 && k>0){
                char chi=st.top();
                int topEle=st.top()-'0';
                st.pop();
                if(topEle>num){
                    k--;
                }
                else{
                    st.push(chi);
                    break;
                }
            }
            st.push(ch);
        }
        string ans="";
        stack<char>helper;
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        while(helper.size()>0 && helper.top()=='0') helper.pop();
        while(helper.size()>0){
            ans+=helper.top();
            helper.pop();
        }
        while(ans.length()>0 && k!=0){
            ans.pop_back();
            k--;
        } 
        if(ans=="") return "0";
        return ans;
    }
};