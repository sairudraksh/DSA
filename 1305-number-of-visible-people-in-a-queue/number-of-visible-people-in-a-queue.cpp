class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,0);
        ans[n-1]=0;
        st.push(arr[n-1]);
        int count=0;
        for(int i=n-2;i>=0;i--){
            count=0;
            while(st.size()>0 && st.top()<arr[i]){
                st.pop();
                count++;
            }
            if(st.size()>0) count++;
            ans[i]=count;
            st.push(arr[i]);
        }
        return ans;
    }
};