class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        int j=0;
        int n=pushed.size();


        stack<int>st;

        while(j<n && i<n){
            st.push(pushed[i]);

            while(st.size()>0 && st.top()==
            popped[j] && j<n){
                st.pop();
                j++;
            }
            i++;
        }

        return st.empty();
    }
};