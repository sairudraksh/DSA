class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        if(k==1) return arr;
        int n=arr.size();
        int ans[n];
        stack<int>st;
        ans[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.size()==0) ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        int j=0;
        vector<int>ans2;
        for(int i=0;i<n-k+1;i++){
            if(j<i) j=i;
            int mx=arr[j];
            while(j<i+k){
                mx=arr[j];
                if(ans[j]>=i+k) break;
                j=ans[j];
            }
            ans2.push_back(mx);
        }
        return ans2;
    }
};                                                                                                                                                                                                                                                                                                                                                                                       