class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        stack<vector<int>>st;
        int n=types.size();
        for(int i=0;i<n;i++){
            if(st.size()>0){
                int f=st.top()[0];
                int s=st.top()[1];
                int freq=st.top()[2];

                if(types[i]==f && colors[i]==s){
                    st.pop();
                    st.push({f,s,freq+1});
                }
                else{
                    st.push({types[i],colors[i],1});
                }

                if(st.top()[2]==groupSize[st.top()[0]]){
                    st.pop();
                }
            }

            else{
                st.push({types[i],colors[i],1});
                if(st.top()[2]==groupSize[st.top()[0]]){
                    st.pop();
                }
            }
        }

        return st.size()==0;
    }
};