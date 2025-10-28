class Solution {
public:
    int n;
    vector<int>findprev(vector<int>&nums){
        vector<int>ans(n,-1);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>findnext(vector<int>&nums){
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }   
    int sumSubarrayMins(vector<int>& arr) {
        n=arr.size();
        vector<int>left=findprev(arr);
        vector<int>right=findnext(arr);

        int total=0;
         int mod = 1e9 + 7;
        for(int i=0;i<n;i++){
            int leftt=i-left[i];
            int rightt=right[i]-i;

            total = (total + ((long long)leftt * rightt % mod) * arr[i] % mod) % mod;
        }
        return total%mod;
    }
};