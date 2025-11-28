class Solution {
public:
    int n;
    int m;
    vector<int> findPSE(vector<int>&heights){
        stack<int>st;
        st.push(0);
        vector<int>ans(m,-1);
        for(int i=1;i<m;i++){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()>0) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findNSE(vector<int>&heights){
        stack<int>st;
        st.push(m-1);
        vector<int>ans(m,m);
        for(int i=m-2;i>=0;i--){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()>0) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int MAH(vector<int>&heights){
        vector<int>NSE=findNSE(heights);
        vector<int>PSE=findPSE(heights);

        int ans=0;
        for(int i=0;i<m;i++){
            int breadth=NSE[i]-PSE[i]-1;
            ans=max(ans,breadth*heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();

        vector<int>heights(m,0);

        for(int i=0;i<m;i++){
            if(matrix[0][i]=='1') heights[i]=1;
            else heights[i]=0;
        }
        int maximum=0;
        maximum=max(maximum,MAH(heights));

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0; 
            }
            maximum=max(maximum,MAH(heights));
        }
        return maximum;
    }
};