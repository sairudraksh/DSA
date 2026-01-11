class Solution {
public:
    vector<int>findpse(vector<int>v){
        int n=v.size();
        stack<int>st;
        vector<int>ans(n,-1);
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0 && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.size()==0) ans[i]=-1;
            else ans[i]=st.top();

            st.push(i);
        }
        return ans;
    }
    vector<int>findnse(vector<int>v){
        int n=v.size();
        stack<int>st;
        vector<int>ans(n,n);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.size()==0) ans[i]=n;
            else ans[i]=st.top();

            st.push(i);
        }
        return ans;
    }
    int MAH(vector<int>&v){
        vector<int>nse=findnse(v);
        vector<int>pse=findpse(v);
        int n=v.size();
        int maximum=0;
        for(int i=0;i<n;i++){
            int length=v[i];
            int breadth=nse[i]-pse[i]-1;
            maximum=max(maximum,length*breadth);
        }
        return maximum;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>v;
        for(int i=0;i<m;i++){
            if(matrix[0][i]=='1') v.push_back(1);
            else v.push_back(0);
        }
        int maximum=0;
        maximum=max(maximum,MAH(v));
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') v[j]++;
                else v[j]=0;
            }
            maximum=max(maximum,MAH(v));
        }
        return maximum;
    }
};