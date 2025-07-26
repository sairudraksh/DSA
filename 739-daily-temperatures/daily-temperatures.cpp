class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>v(n,0);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                st.pop();// remove smaller as they are smaller than current element only so before elements(that will come in next iterations) will oviously have next greater = curr element as other were smaller
            }
            if(!st.empty()) v[i]=st.top()-i;
            st.push(i);
        }
        return v;
    }
};