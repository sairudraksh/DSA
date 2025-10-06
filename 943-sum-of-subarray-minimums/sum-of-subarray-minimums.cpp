class Solution {
public:
    vector<int>NextSmaller(vector<int>&nums){
        int n=nums.size();
        vector<int>v(n,n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty())v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    vector<int>PreviousSmaller(vector<int>&nums){
        int n=nums.size();
        vector<int>v(n,-1);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){// not greater than equal to here as other wise it will be recomputed so either do >= above or here
                st.pop();
            }

            if(!st.empty()) v[i]=st.top();

            st.push(i);
        }
        return v;
    }
    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        vector<int>nse=NextSmaller(nums);
        vector<int>pse=PreviousSmaller(nums);

        int total=0;
         int mod = 1e9 + 7;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;

            total = (total + ((long long)left * right % mod) * nums[i] % mod) % mod;
        }
        return total%mod;
    }
};