class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>psi(n,-1);
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()>0) psi[i]=st.top();
            st.push(i);
        }

        stack<int>st2;
        vector<int>nsi(n,n);
        st2.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st2.size()>0 && heights[st2.top()]>=heights[i]){
                st2.pop();
            }
            if(st2.size()>0) nsi[i]=st2.top();
            st2.push(i);
        }
        int maximum=0;
        for(int i=0;i<n;i++){
            int length=heights[i];
            int breadth=nsi[i]-psi[i]-1;
            int area=length*breadth;
            maximum=max(maximum,area);
        }
        return maximum;
    }
};