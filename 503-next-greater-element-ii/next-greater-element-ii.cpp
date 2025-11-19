class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n,-1);

        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.size()>0){
                ans[i]=nums[st.top()];
            }
            else{
                for(int k=0;k<n;k++){
                    if(nums[k]>nums[i]){
                        ans[i]=nums[k];
                        break;
                    }
                }
            }
            st.push(i);
        }
        return ans;
    }
};